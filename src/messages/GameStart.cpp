//
// Created by timluchterhand on 12.12.20.
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
