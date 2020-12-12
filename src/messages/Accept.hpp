//
// Created by timluchterhand on 12.12.20.
//

#ifndef SECRETBUNDESTAGSERVER_ACCEPT_HPP
#define SECRETBUNDESTAGSERVER_ACCEPT_HPP

#include "Message.hpp"

namespace messages {
    struct Accept : public Message {
        Accept() = default;
    };
}

#endif //SECRETBUNDESTAGSERVER_ACCEPT_HPP
