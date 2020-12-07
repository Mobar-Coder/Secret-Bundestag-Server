/**
 * @file ConnectionHandler.hpp
 * @author paul
 * @date 30.11.20
 * Description here TODO
 */
#ifndef SECRETBUNDESTAGSERVER_CONNECTIONHANDLER_HPP
#define SECRETBUNDESTAGSERVER_CONNECTIONHANDLER_HPP


#include <nlohmann/json.hpp>
#include <WebsocketCpp/src/Server/WebSocketServer.hpp>
#include <cstdint>
#include "../util/Logging.hpp"
#include "../messages/Message.hpp"

namespace comm {
    class ConnectionHandler {
        public:
            ConnectionHandler(uint16_t port, util::Logging &log);

            void send(const std::shared_ptr<const messages::Message> &message, std::size_t client) const;

            const websocketcpp::util::Listener<std::size_t> onConnect;

            const websocketcpp::util::Listener<std::shared_ptr<const messages::Message>, std::size_t> onReceive;

            const websocketcpp::util::Listener<std::size_t> onClose;

            void closeConnection(std::size_t id);

        private:
            void connectListener(const std::shared_ptr<websocketcpp::Connection> &connection);

            void receiveListener(std::size_t id, const std::string &text);

            void closeListener(const std::shared_ptr<websocketcpp::Connection> &connection);

            websocketcpp::WebSocketServer webSocketServer;
            std::map<std::size_t, std::shared_ptr<websocketcpp::Connection>> connections;
            std::size_t idCount;
            util::Logging &log;
    };
}

#endif //SECRETBUNDESTAGSERVER_CONNECTIONHANDLER_HPP
