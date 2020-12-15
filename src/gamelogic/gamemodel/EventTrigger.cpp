/**
 * @file EventTrigger.cpp
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

        auto res = false;

        switch (triggerCompositor) {

            case TriggerCompositor::And:
                res = lhs->triggered(environment) && rhs->triggered(environment);
                break;
            case TriggerCompositor::Or:
                res = lhs->triggered(environment) || rhs->triggered(environment);
                break;
        }

        return res;
    }
}
