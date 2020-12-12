/**
 * @file LobbyHandler.cpp
 * @author paul
 * @date 01.12.20
 * Description here TODO
 */
#include "LobbyHandler.hpp"

#include "../messages/JoinRequest.hpp"
#include "../util/IsType.hpp"

namespace comm {
    LobbyHandler::LobbyHandler(uint16_t port, util::Logging &log) : log{log}, connectionHandler{port, log} {
        connectionHandler.onReceive.subscribe([this](auto m, auto id) { this->receiveListener(m, id); });
        connectionHandler.onClose.subscribe([this](auto id) { this->closeListener(id); });
    }

    void LobbyHandler::receiveListener(const std::shared_ptr<const messages::Message> &message, std::size_t id) {
        auto lobbyIt = userLobbyMap.find(id);
        auto isInLobby = lobbyIt != userLobbyMap.end();

        if (util::isType<const messages::JoinRequest>(message)) {
            if (!isInLobby) {
                auto joinRequest = std::dynamic_pointer_cast<const messages::JoinRequest>(message);
                std::shared_ptr<Lobby> lobbyPtr;
                if (lobbyNameMap.find(joinRequest->lobby) == lobbyNameMap.end()) {
                    log.info("Creating Lobby " + joinRequest->lobby + " for " +
                        joinRequest->name + " (" + std::to_string(id) + ")");
                    lobbyPtr = std::make_shared<Lobby>(
                            [this](auto msg, auto id) {
                                this->connectionHandler.send(msg, id);
                            },
                            util::Logging{log, joinRequest->lobby});
                    lobbyNameMap.emplace(joinRequest->lobby, lobbyPtr);
                } else {
                    log.info(joinRequest->name + " (" + std::to_string(id) + ")"
                        + " joins " + joinRequest->lobby);
                    lobbyPtr = lobbyNameMap.find(joinRequest->lobby)->second;
                }

                userLobbyMap.emplace(id, lobbyPtr);
                lobbyPtr->onJoin(id);
            } else {
                log.error("User sent JoinRequest but already in lobby!");
                connectionHandler.closeConnection(id);
            }
        } else {
            if (isInLobby) {
                lobbyIt->second->onReceive(message, id);
            } else {
                log.error("User not in lobby but send message");
                connectionHandler.closeConnection(id);
            }
        }
    }

    void LobbyHandler::closeListener(std::size_t id) {
        auto lobbyIt = userLobbyMap.find(id);
        if (lobbyIt != userLobbyMap.end()) {
            lobbyIt->second->onLeave(id);

            // Check if another user is in this lobby
            auto userInLobby = false;
            for (const auto &[id, lobbyPTr] : userLobbyMap) {
                if (lobbyPTr == lobbyIt->second) {
                    userInLobby = true;
                    break;
                }
            }

            // Definitely erase user
            userLobbyMap.erase(id);

            // If lobby is now empty also erase from lobbyNameMap
            if (not userInLobby) {
                for (auto &[name, lobbyPtr] : lobbyNameMap) {
                    if (lobbyPtr == lobbyIt->second) {
                        lobbyNameMap.erase(name);
                        log.info("Lobby " + name + " closed");
                        break;
                    }
                }
            }

        } else {
            log.info("User without lobby left!");
        }
    }

}
