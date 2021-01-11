//
// Created by tarik on 04.01.20.
//

#include "GameStart.hpp"

namespace messages {
    CLASS(GameStart)

    GameStart::GameStart() {
        PROPERTY(fraction)
        PROPERTY(role)
        PROPERTY(players)
        PROPERTY(hitler)
        PROPERTY(teamMates)
    }
}
