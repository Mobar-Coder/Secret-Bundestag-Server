/**
 * @file SingleCardEventTrigger.cpp
 * @author jonas
 * @date 14.12.20
 * Description here TODO
 */

#include "SingleCardEventTrigger.hpp"

namespace GameModel {

    SingleCardEventTrigger::SingleCardEventTrigger(CardType cardType, std::size_t threshold,
                                                   TriggerComparator triggerComparator) :
                                                     cardType(cardType), threshold(threshold),
                                                     triggerComparator(triggerComparator) {
    }

    auto SingleCardEventTrigger::triggered(const std::shared_ptr<const Environment> &environment) -> bool {

        switch (triggerComparator) {

            case TriggerComparator::EQUAL:
                return environment->getNumberOfPlayedPolicies(cardType) == threshold;

            case TriggerComparator::LESS:
                return environment->getNumberOfPlayedPolicies(cardType) < threshold;

            case TriggerComparator::GREATER:
                return environment->getNumberOfPlayedPolicies(cardType) > threshold;

            case TriggerComparator::UNEQUAL:
                return environment->getNumberOfPlayedPolicies(cardType) != threshold;

            default:
                throw std::logic_error("The selected trigger comparator option is not implemented!");
        }
    }
}
