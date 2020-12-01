/**
 * @file Lobby.hpp
 * @author paul
 * @date 01.12.20
 * Description here TODO
 */
#ifndef SECRETBUNDESTAGSERVER_LOBBY_HPP
#define SECRETBUNDESTAGSERVER_LOBBY_HPP

#include "../messages/Message.hpp"

namespace comm {
    class Lobby {
        public:
            void onJoin(std::size_t id);

            void onReceive(const std::shared_ptr<const messages::Message> &msg, std::size_t id);

            void onClose(std::size_t id);

        private:

    };
}

#endif //SECRETBUNDESTAGSERVER_LOBBY_HPP
