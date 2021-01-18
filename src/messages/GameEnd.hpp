//
// Created by tarik on 04.01.20.
//

#ifndef SECRETBUNDESTAGSERVER_ACCEPT_HPP
#define SECRETBUNDESTAGSERVER_ACCEPT_HPP

#include "Message.hpp"

namespace messages {
    struct GameEnd : public Message {
        GameEnd();
        std::string winnerTeam{};
    };
}

#endif //SECRETBUNDESTAGSERVER_ACCEPT_HPP
