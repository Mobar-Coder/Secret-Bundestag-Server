/**
 * @file AbstractEventTrigger.hpp
 * @author jonas
 * @date 14.12.20
 * Description here TODO
 */

#ifndef SECRETBUNDESTAGSERVER_ABSTRACTEVENTTRIGGER_HPP
#define SECRETBUNDESTAGSERVER_ABSTRACTEVENTTRIGGER_HPP

#include "Environment.hpp"

/**
 * @namespace GameModel
 * The namespace for the game model.
 */
namespace GameModel {

    /**
     * @class AbstractEventTrigger
     * This class is an abstract interface for an event.
     */
    class AbstractEventTrigger {

        public:

            virtual auto triggered(const std::shared_ptr<const Environment> &environment) -> bool = 0;
    };
}

#endif //SECRETBUNDESTAGSERVER_ABSTRACTEVENTTRIGGER_HPP
