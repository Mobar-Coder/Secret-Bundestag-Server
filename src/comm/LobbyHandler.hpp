/**
 * @file LobbyHandler.hpp
 * @author paul
 * @date 01.12.20
 * Description here TODO
 */
#ifndef SECRETBUNDESTAGSERVER_LOBBYHANDLER_HPP
#define SECRETBUNDESTAGSERVER_LOBBYHANDLER_HPP

#include <set>

#include "ConnectionHandler.hpp"
#include "Lobby.hpp"

namespace comm {
    class LobbyHandler {
        public:
            LobbyHandler(uint16_t port, util::Logging &log);

        private:
            //@TODO send function

            void receiveListener(const std::shared_ptr<const messages::Message> &message, std::size_t id);

            void closeListener(std::size_t id);

            util::Logging &log;

            ConnectionHandler connectionHandler;

            std::map<std::size_t, std::shared_ptr<Lobby>> userLobbyMap;
            std::map<std::string, std::shared_ptr<Lobby>> lobbyNameMap;
    };
}

#endif //SECRETBUNDESTAGSERVER_LOBBYHANDLER_HPP
