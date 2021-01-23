//
// Created by tarik on 04.01.21.
//

#ifndef SECRETBUNDESTAGSERVER_REQUESTDECISION_HPP
#define SECRETBUNDESTAGSERVER_REQUESTDECISION_HPP

#include "Message.hpp"

namespace messages {
    struct RequestDecision : public Message {
        RequestDecision();
        std::string type{};
        std::vector<std::string> choices;

    };
}

#endif //SECRETBUNDESTAGSERVER_REQUESTDECISION_HPP
