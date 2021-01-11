//
// Created by tarik on 04.01.20.
//

#ifndef SECRETBUNDESTAGSERVER_GAMESTART_HPP
#define SECRETBUNDESTAGSERVER_GAMESTART_HPP
#include "Message.hpp"
#include "Player.hpp"
#include "OptionalSerializer.hpp"
#include <optional>

namespace messages {
    struct GameStart: public Message {
        GameStart();
        std::string fraction;
        std::string role;
        std::vector<Player> players;
        std::optional<std::string> hitler;
        std::vector<std::string> teamMates;
    };
}


#endif //SECRETBUNDESTAGSERVER_GAMESTART_HPP
