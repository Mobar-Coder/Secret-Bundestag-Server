/**
 * @file JoinRequest.hpp
 * @author paul
 * @date 01.12.20
 * Description here TODO
 */
#ifndef SECRETBUNDESTAGSERVER_JOINREQUEST_HPP
#define SECRETBUNDESTAGSERVER_JOINREQUEST_HPP

#include "Message.hpp"

namespace messages {
    struct JoinRequest : public Message {
        JoinRequest();

        std::string lobbyName;
    };
}

#endif //SECRETBUNDESTAGSERVER_JOINREQUEST_HPP
