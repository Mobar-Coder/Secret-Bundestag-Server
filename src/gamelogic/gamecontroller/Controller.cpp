/**
 * @file Controller.cpp
 * @author bjoern
 * @date 01.12.20
 * Description here TODO
 */

#include "Controller.hpp"

namespace GameController {

    Controller::Controller(const int &players) {
        environment = new GameModel::Environment(&players);
        phase = GameController::Phase::PASSCANDIDACY;
    }







}
