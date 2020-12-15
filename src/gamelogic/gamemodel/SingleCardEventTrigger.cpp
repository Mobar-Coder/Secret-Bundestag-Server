/**
 * @file SingleCardEventTrigger.cpp.c
 * @author jonas
 * @date 14.12.20
 * Description here TODO
 */

#include "SingleCardEventTrigger.hpp"

namespace GameModel {

    SingleECardEventTrigger::SingleECardEventTrigger(CardType cardType, std::size_t threshold,
                                                     TriggerComparator triggerComparator) :
                                                     cardType(cardType), threshold(threshold),
                                                     triggerComparator(triggerComparator) {
    }

    auto SingleECardEventTrigger::triggered(std::shared_ptr<const Environment> environment) -> bool {
        // ToDo: implement
        auto res = false;
        auto a = environment->getPlayers();
        switch (triggerComparator) {
            case TriggerComparator::Equal:
                break;
            case TriggerComparator::Less:
                break;
            case TriggerComparator::Greater:
                break;
            case TriggerComparator::Unequal:
                break;
        }

        return res;
    }
}
