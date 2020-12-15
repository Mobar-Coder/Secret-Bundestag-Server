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

        auto res = false;

        switch (triggerComparator) {
            case TriggerComparator::EQUAL:
                res = environment->getNumberOfPlayedPolicies(cardType) == threshold;
                break;
            case TriggerComparator::LESS:
                res = environment->getNumberOfPlayedPolicies(cardType) < threshold;
                break;
            case TriggerComparator::GREATER:
                res = environment->getNumberOfPlayedPolicies(cardType) > threshold;
                break;
            case TriggerComparator::UNEQUAL:
                res = environment->getNumberOfPlayedPolicies(cardType) != threshold;
                break;
            default:
                throw std::logic_error("The selected trigger comparator option is not implemented!");
        }

        return res;
    }
}
