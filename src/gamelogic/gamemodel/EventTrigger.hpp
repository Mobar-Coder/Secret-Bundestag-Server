/**
 * @file EventTrigger.hpp.h
 * @author jonas
 * @date 14.12.20
 * Description here TODO
 */

#ifndef SECRETBUNDESTAGSERVER_EVENTTRIGGER_HPP
#define SECRETBUNDESTAGSERVER_EVENTTRIGGER_HPP

#include "AbstractEventTrigger.hpp"
#include "../enum/TriggerCompositor.hpp"

namespace GameModel {

    class EventTrigger : AbstractEventTrigger {

        private:
            std::shared_ptr<AbstractEventTrigger> lhs;
            std::shared_ptr<AbstractEventTrigger> rhs;

            TriggerCompositor triggerCompositor;

        public:
            EventTrigger(std::shared_ptr<AbstractEventTrigger> lhs, std::shared_ptr<AbstractEventTrigger> rhs ,
                         TriggerCompositor triggerCompositor);

            auto triggered(std::shared_ptr<const Environment> environment) -> bool override;
    };
}

#endif //SECRETBUNDESTAGSERVER_EVENTTRIGGER_HPP
