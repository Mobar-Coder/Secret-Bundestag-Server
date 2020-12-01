/**
 * @file ConnectionHandler.hpp
 * @author paul
 * @date 30.11.20
 * Description here TODO
 */
#ifndef SECRETBUNDESTAGSERVER_CONNECTIONHANDLER_HPP
#define SECRETBUNDESTAGSERVER_CONNECTIONHANDLER_HPP


#include <nlohmann/json.hpp>
#include <WebsocketCPP/src/Server/WebSocketServer.hpp>
#include <cstdint>
#include "../util/Logging.hpp"
#include "../messages/Message.hpp"

namespace comm {
    class ConnectionHandler {
        public:
            ConnectionHandler(uint16_t port, util::Logging &log);

            void send(const std::shared_ptr<messages::Message> &message, std::size_t client) const;

            const websocket::util::Listener<std::size_t> onConnect;

            const websocket::util::Listener<std::shared_ptr<messages::Message>, std::size_t> onReceive;

            const websocket::util::Listener<std::size_t> onClose;

        private:
            void connectListener(const std::shared_ptr<websocket::network::Connection> &connection);

            void receiveListener(std::size_t id, const std::string &text);

            void closeListener(const std::shared_ptr<websocket::network::Connection> &connection);

            void closeWithId(std::size_t id);

            websocket::network::WebSocketServer webSocketServer;
            std::map<int, std::shared_ptr<websocket::network::Connection>> connections;
            std::size_t idCount;
            util::Logging &log;
    };
}

#endif //SECRETBUNDESTAGSERVER_CONNECTIONHANDLER_HPP
