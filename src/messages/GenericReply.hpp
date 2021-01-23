//
// Created by tarik on 04.01.21.
//

#ifndef SECRETBUNDESTAGSERVER_GENERICREPLY_HPP
#define SECRETBUNDESTAGSERVER_GENERICREPLY_HPP

#include "Message.hpp"

namespace messages {
    struct GenericReply : public Message {
        GenericReply();
        std::string decision{};
    };
}

#endif //SECRETBUNDESTAGSERVER_GENERICREPLY_HPP
