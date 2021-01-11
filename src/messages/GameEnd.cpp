//
// Created by tarik on 04.01.20.
//

#include "GameEnd.hpp"

namespace messages {
    CLASS(GameEnd)

    GameEnd::GameEnd() {
        PROPERTY(winnerTeam)
    }
}
