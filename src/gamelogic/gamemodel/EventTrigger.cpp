/**
 * @file EventTrigger.cpp.c
 * @author jonas
 * @date 14.12.20
 * Description here TODO
 */

#include "EventTrigger.hpp"

#include <utility>

namespace GameModel {

    EventTrigger::EventTrigger(std::shared_ptr<AbstractEventTrigger> lhs, std::shared_ptr<AbstractEventTrigger> rhs,
                               TriggerCompositor triggerCompositor) :
                               lhs(std::move(lhs)), rhs(std::move(rhs)), triggerCompositor(triggerCompositor) {
    }

    auto EventTrigger::triggered(std::shared_ptr<const Environment> environment) -> bool {
        // ToDo: implement
        auto a = environment->getPlayers();
        return false;
    }
}
