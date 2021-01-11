//
// Created by tarik on 04.01.20.
//

#include "GameState.hpp"

namespace messages {
    CLASS(GameState)

    GameState::GameState() {
        PROPERTY(liberalPolicies)
        PROPERTY(fascistPolicies)
        PROPERTY(chancellor)
        PROPERTY(electionTracker)
        PROPERTY(players)
        PROPERTY(cardPile)
        PROPERTY(discardPile)

    }
}
