/**
 * @file EventTrigger.hpp
 * @author jonas
 * @date 14.12.20
 * Description here TODO
 */

#ifndef SECRETBUNDESTAGSERVER_EVENTTRIGGER_HPP
#define SECRETBUNDESTAGSERVER_EVENTTRIGGER_HPP

#include "AbstractEventTrigger.hpp"
#include "../enum/TriggerCompositor.hpp"

/**
 * @namespace GameModel
 * The namespace for the game model.
 */
namespace GameModel {

    /**
     * @class EventTrigger
     * @extends AbstractEventTrigger
     * This class represents a composite event.
     */
    class EventTrigger : AbstractEventTrigger {

        private:
            std::shared_ptr<AbstractEventTrigger> lhs;
            std::shared_ptr<AbstractEventTrigger> rhs;

            TriggerCompositor triggerCompositor;

        public:

            /**
             * Main Constructor of the EventTrigger class.
             * @param lhs
             * @param rhs
             * @param triggerCompositor
             */
            EventTrigger(std::shared_ptr<AbstractEventTrigger> lhs, std::shared_ptr<AbstractEventTrigger> rhs,
                         TriggerCompositor triggerCompositor);

            /**
             *
             * @implements AbstractEventTrigger::triggered(std::shared_ptr<const Environment> environment)
             * @param environment
             * @return
             */
            auto triggered(std::shared_ptr<const Environment> environment) -> bool override;
    };
}

#endif //SECRETBUNDESTAGSERVER_EVENTTRIGGER_HPP
