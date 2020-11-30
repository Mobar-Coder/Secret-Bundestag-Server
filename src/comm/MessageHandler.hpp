/**
 * @file MessageHandler.hpp
 * @author paul
 * @date 30.11.20
 * Description here TODO
 */
#ifndef SECRETBUNDESTAGSERVER_MESSAGEHANDLER_HPP
#define SECRETBUNDESTAGSERVER_MESSAGEHANDLER_HPP


#include <nlohmann/json.hpp>
#include <WebsocketCPP/src/Server/WebSocketServer.hpp>
#include <cstdint>
#include "../util/Logging.hpp"

namespace comm {
    class MessageHandler {
        public:
            MessageHandler(uint16_t port, util::Logging &log);

            void send(const nlohmann::json& message, std::size_t client);

            const websocket::util::Listener<std::size_t> onConnect;

            const websocket::util::Listener<nlohmann::json, std::size_t> onReceive;

            const websocket::util::Listener<std::size_t> onClose;

        private:
            void connectListener(const std::shared_ptr<websocket::network::Connection>& connection);

            void receiveListener(std::size_t id, const std::string& msg);

            void closeListener(const std::shared_ptr<websocket::network::Connection> &connection);

            void closeWithId(std::size_t id);

            websocket::network::WebSocketServer webSocketServer;
            std::map<int, std::shared_ptr<websocket::network::Connection>> connections;
            std::size_t idCount;
            util::Logging &log;
    };
}

#endif //SECRETBUNDESTAGSERVER_MESSAGEHANDLER_HPP
