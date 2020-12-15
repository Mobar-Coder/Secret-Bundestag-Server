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

    auto SingleCardEventTrigger::triggered(std::shared_ptr<const Environment> environment) -> bool {

        auto res = false;

        switch (triggerComparator) {
            case TriggerComparator::Equal:
                res = environment->getNumberOfPlayedPolicies(cardType) == threshold;
                break;
            case TriggerComparator::Less:
                res = environment->getNumberOfPlayedPolicies(cardType) < threshold;
                break;
            case TriggerComparator::Greater:
                res = environment->getNumberOfPlayedPolicies(cardType) > threshold;
                break;
            case TriggerComparator::Unequal:
                res = environment->getNumberOfPlayedPolicies(cardType) != threshold;
                break;
        }

        return res;
    }
}
