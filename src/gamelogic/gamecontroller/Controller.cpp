/**
 * @file Controller.cpp
 * @author bjoern
 * @date 01.12.20
 * Description here TODO
 */

#include "Controller.hpp"

namespace GameController {

    Controller::Controller(std::vector<std::shared_ptr<GameModel::Environment>> environment)
            : environment(environment) {
        phase = GameController::Phase::PASSCANDIDACY;
    }







}
