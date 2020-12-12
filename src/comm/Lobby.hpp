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
            using SendF = std::function<void(const std::shared_ptr<messages::Message>&, std::size_t)>;
        public:
            Lobby(SendF sendToClient, util::Logging log);

            void onJoin(std::size_t id);

            void onReceive(const std::shared_ptr<const messages::Message> &msg, std::size_t id);

            void onLeave(std::size_t);

        private:
            SendF sendToClient;

            util::Logging log;
    };
}

#endif //SECRETBUNDESTAGSERVER_LOBBY_HPP
