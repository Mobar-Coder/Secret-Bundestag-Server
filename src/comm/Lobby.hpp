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
            using KickF = std::function<void(std::size_t)>;
        public:
            Lobby(SendF sendToClient, KickF kickPlayer, util::Logging log);

            void onJoin(std::size_t id);

            void onReceive(const std::shared_ptr<const messages::Message> &message, std::size_t id);

            void onLeave(std::size_t id);

        private:
            SendF sendToClient;
            KickF kickPlayer;
            util::Logging log;
            std::vector<std::size_t> playerIds;
            void sendError(const std::string &message, std::size_t id);
    };
}

#endif //SECRETBUNDESTAGSERVER_LOBBY_HPP
