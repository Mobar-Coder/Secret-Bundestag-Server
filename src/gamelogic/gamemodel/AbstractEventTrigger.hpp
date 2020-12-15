/**
 * @file AbstractEventTrigger.hpp.h
 * @author jonas
 * @date 14.12.20
 * Description here TODO
 */

#ifndef SECRETBUNDESTAGSERVER_ABSTRACTEVENTTRIGGER_HPP
#define SECRETBUNDESTAGSERVER_ABSTRACTEVENTTRIGGER_HPP

#include "Environment.hpp"

namespace GameModel {

    class AbstractEventTrigger {

        public:

            virtual auto triggered(std::shared_ptr<const Environment> environment) -> bool = 0;
    };
}

#endif //SECRETBUNDESTAGSERVER_ABSTRACTEVENTTRIGGER_HPP
