/**
 * @file Lobby.cpp
 * @author paul
 * @date 01.12.20
 * Description here TODO
 */
#include "Lobby.hpp"
#include "../messages/Accept.hpp"

#include <utility>

namespace comm {
    Lobby::Lobby(SendF sendToClient, util::Logging log) : sendToClient{std::move(sendToClient)}, log{std::move(log)} {}

    void Lobby::onJoin(std::size_t id) {
        auto accMsg = std::make_shared<messages::Accept>();
        accMsg->leader = playerIds.empty();
        sendToClient(accMsg, id);
        playerIds.emplace_back(id);
    }

    void Lobby::onReceive(const std::shared_ptr<const messages::Message> &, std::size_t) { // NOLINT @TODO add code

    }

    void Lobby::onLeave(std::size_t) { // NOLINT @TODO add code

    }
}
