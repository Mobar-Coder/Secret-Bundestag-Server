/**
 * @file Lobby.hpp
 * @author paul
 * @date 01.12.20
 * Description here TODO
 */
#ifndef SECRETBUNDESTAGSERVER_LOBBY_HPP
#define SECRETBUNDESTAGSERVER_LOBBY_HPP

#include "../messages/Message.hpp"
#include "../util/Logging.hpp"

namespace comm {
    class Lobby {
        public:
            explicit Lobby(util::Logging log);

            void onJoin(std::size_t id);

            void onReceive(const std::shared_ptr<const messages::Message> &msg, std::size_t id);

            void onClose(std::size_t id);

        private:
            util::Logging log;
    };
}

#endif //SECRETBUNDESTAGSERVER_LOBBY_HPP
