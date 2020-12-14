/**
 * @file SinglrCardEventTrigger.hpp.h
 * @author jonas
 * @date 14.12.20
 * Description here TODO
 */

#ifndef SECRETBUNDESTAGSERVER_SINGLECARDEVENTTRIGGER_HPP
#define SECRETBUNDESTAGSERVER_SINGLECARDEVENTTRIGGER_HPP

#include "AbstractEventTrigger.hpp"
#include "Environment.hpp"
#include "../enum/TriggerComparator.hpp"

namespace GameModel {

    class SingleECardEventTrigger : AbstractEventTrigger {

        private:
            CardType cardType;
            std::size_t threshold{};

            TriggerComparator triggerComparator;

        public:
            SingleECardEventTrigger(CardType cardType, std::size_t threshold, TriggerComparator triggerComparator);

            auto triggered(std::shared_ptr<const Environment> environment) -> bool override;
    };
}

#endif //SECRETBUNDESTAGSERVER_SINGLECARDEVENTTRIGGER_HPP
