/**
 * @file ConnectionHandler.cpp
 * @author paul
 * @date 30.11.20
 * Description here TODO
 */
#include "ConnectionHandler.hpp"

namespace comm {
    ConnectionHandler::ConnectionHandler(uint16_t port, util::Logging &log) :
            webSocketServer{port, ""},
            idCount{0},
            log{log} {
        this->webSocketServer.connectionListener.subscribe([this](auto c) { connectListener(c); });
        this->webSocketServer.closeListener.subscribe([this](auto c) { closeListener(c); });
    }

    void ConnectionHandler::connectListener(const std::shared_ptr<websocket::network::Connection> &connection) {
        this->connections.emplace(idCount, connection);
        connection->receiveListener.subscribe([this, id = this->idCount](auto msg) { receiveListener(id, msg); });
        onConnect(this->idCount);
        this->idCount += 1;
    }


    void ConnectionHandler::send(const std::shared_ptr<const messages::Message> &message, std::size_t client) const {
        if (connections.find(client) != connections.end()) {
            try {
                connections.at(client)->send(message->toJson().dump(4));
            } catch (std::runtime_error &e) {
                log.error("Trying to send message to user that already left!");
            }
        } else {
            log.error("Trying to send a non registered user!");
        }
    }

    void ConnectionHandler::receiveListener(std::size_t id, const std::string &text) {
        if (not text.empty()) {
            try {
                auto json = nlohmann::json::parse(text);
                auto message = messages::Message::fromJson(json);

                onReceive(message, id);
            } catch (nlohmann::json::exception &e) {
                log.error("Got invalid json!");
                log.debug(e.what());
                closeConnection(id);
            } catch (std::runtime_error &e) {
                log.error("Invalid json format!");
                log.debug(e.what());
                closeConnection(id);
            }
        }
    }

    void ConnectionHandler::closeListener(const std::shared_ptr<websocket::network::Connection> &connection) {
        for (auto it = this->connections.begin(); it != this->connections.end(); ++it) {
            if (it->second.get() == connection.get()) {
                closeConnection(it->first);
            }
        }
    }

    void ConnectionHandler::closeConnection(std::size_t id) {
        auto it = this->connections.find(id);
        if (it != this->connections.end()) {
            this->connections.erase(it);
            onClose(it->first);
        }
    }
}
