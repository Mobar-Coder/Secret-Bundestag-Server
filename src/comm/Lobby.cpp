/**
 * @file Lobby.cpp
 * @author paul
 * @date 01.12.20
 * Description here TODO
 */
#include "Lobby.hpp"
#include "../messages/Accept.hpp"
#include "../util/IsType.hpp"
#include "../messages/StartRequest.hpp"
#include "../messages/Error.hpp"

#include <utility>

namespace comm {
    Lobby::Lobby(SendF sendToClient, util::Logging log) : sendToClient{std::move(sendToClient)}, log{std::move(log)} {}

    void Lobby::onJoin(std::size_t id) {
        auto accMsg = std::make_shared<messages::Accept>();
        accMsg->leader = playerIds.empty();
        sendToClient(accMsg, id);
        playerIds.emplace_back(id);
    }

    void Lobby::onReceive(const std::shared_ptr<const messages::Message> &message, std::size_t id) {
        if (util::isType<messages::StartRequest>(message)) {
            if (id != playerIds.front()) {
                sendError("You are not the lobby leader", id);
            } else {
                sendError("Not implemented yet", id);
            }
        } else {
            sendError("Unknown message type", id);
        }
    }

    void Lobby::onLeave(std::size_t) { // NOLINT @TODO add code

    }

    void Lobby::sendError(const std::string &message, std::size_t id) {
        auto error = std::make_shared<messages::Error>();
        error->message = message;
        log.info("Sending error to " + std::to_string(id) + " :" + message);
        sendToClient(error, id);
    }
}
