/**
 * @file Controller.hpp
 * @author bjoern
 * @date 01.12.20
 * Description here TODO
 */

#ifndef SECRETBUNDESTAGSERVER_CONTROLLER_HPP
#define SECRETBUNDESTAGSERVER_CONTROLLER_HPP

#include "../Environment.hpp"

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
            Environment environment;
            Phase phase;

        public:
            explicit Controller(const std::vector<Player> &players);
    };
}


#endif // SECRETBUNDESTAGSERVER_CONTROLLER_HPP

