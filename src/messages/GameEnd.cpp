//
// Created by timluchterhand on 12.12.20.
//

#include "GameEnd.hpp"

namespace messages {
    CLASS(GameEnd)

    GameEnd::GameEnd() {
        PROPERTY(winnerTeam)
    }
}
