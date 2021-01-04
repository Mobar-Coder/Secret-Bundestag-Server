//
// Created by timluchterhand on 12.12.20.
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
