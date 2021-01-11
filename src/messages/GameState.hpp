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
    struct GameState: public Message {
        GameState();
        int liberalPolicies;
        int fascistPolicies;
        std::optional<std::string> chancellor;
        int electionTracker;
        std::vector<Player> players;
        int cardPile;
        int discardPile;
    };
}


#endif //SECRETBUNDESTAGSERVER_GAMESTART_HPP
