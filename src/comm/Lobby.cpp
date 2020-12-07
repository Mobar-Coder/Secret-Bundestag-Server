/**
 * @file Lobby.cpp
 * @author paul
 * @date 01.12.20
 * Description here TODO
 */
#include "Lobby.hpp"

#include <utility>

namespace comm {
    Lobby::Lobby(util::Logging log) : log{std::move(log)} {}

    void Lobby::onJoin(std::size_t) {

    }

    void Lobby::onReceive(const std::shared_ptr<const messages::Message> &, std::size_t) {

    }

    void Lobby::onClose(std::size_t) {

    }
}
