/**
 * @file Controller.hpp
 * @author bjoern
 * @date 01.12.20
 * Description here TODO
 */

#ifndef SECRETBUNDESTAGSERVER_CONTROLLER_HPP
#define SECRETBUNDESTAGSERVER_CONTROLLER_HPP

#include "../gamemodel/Environment.hpp"
#include "../../messages/Error.hpp"
#include "../../messages/Message.hpp"

namespace GameController {

    enum Phase{
        PASSCANDIDACY,
        NOMINATECHANCELLOR,
        VOTEGOVERNMENT,
        LEGISLATIVESESSION1,
        LEGISLATIVESESSION2,
        EXECUTIVEACTION,
        VETO
    };

    class Controller {

        private:
            GameModel::Environment environment;
            Phase phase;

        public:
            explicit Controller(const std::vector<GameModel::Player> &players);
            void processMessage();

    };
}


#endif // SECRETBUNDESTAGSERVER_CONTROLLER_HPP

