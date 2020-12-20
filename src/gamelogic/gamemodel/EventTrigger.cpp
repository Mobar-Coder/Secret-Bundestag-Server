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

    auto EventTrigger::triggered(const std::shared_ptr<const Environment> &environment) -> bool {

        switch (triggerCompositor) {

            case TriggerCompositor::AND:
                return lhs->triggered(environment) && rhs->triggered(environment);

            case TriggerCompositor::OR:
                return lhs->triggered(environment) || rhs->triggered(environment);

            default:
                throw std::logic_error("The selected trigger compositor option is not implemented!");
        }
    }
}
