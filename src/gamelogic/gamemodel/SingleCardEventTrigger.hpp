/**
 * @file SingleCardEventTrigger.hpp
 * @author jonas
 * @date 14.12.20
 * Description here TODO
 */

#ifndef SECRETBUNDESTAGSERVER_SINGLECARDEVENTTRIGGER_HPP
#define SECRETBUNDESTAGSERVER_SINGLECARDEVENTTRIGGER_HPP

#include "AbstractEventTrigger.hpp"
#include "Environment.hpp"
#include "../enum/TriggerComparator.hpp"

/**
 * @namespace GameModel
 * The namespace for the game model.
 */
namespace GameModel {

    /**
     * @class SingleCardEventTrigger
     * @extends AbstractEventTrigger
     * This class represents a single card event.
     */
    class SingleCardEventTrigger : AbstractEventTrigger {

        private:

            CardType cardType;
            std::size_t threshold;
            TriggerComparator triggerComparator;

        public:

            /**
             * Main Constructor of the SingleCardEventTrigger class.
             * @param cardType
             * @param threshold
             * @param triggerComparator
             */
            SingleCardEventTrigger(CardType cardType, std::size_t threshold, TriggerComparator triggerComparator);

            /**
             *
             * @implements AbstractEventTrigger::triggered(std::shared_ptr<const Environment> environment)
             * @param environment
             * @return
             */
            auto triggered(const std::shared_ptr<const Environment> &environment) -> bool override;
    };
}

#endif //SECRETBUNDESTAGSERVER_SINGLECARDEVENTTRIGGER_HPP
