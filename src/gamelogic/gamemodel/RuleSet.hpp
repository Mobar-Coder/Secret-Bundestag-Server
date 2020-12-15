/**
 * @file RuleSet.hpp.h
 * @author jonas
 * @date 14.12.20
 * Description here TODO
 */

#ifndef SECRETBUNDESTAGSERVER_RULESET_HPP
#define SECRETBUNDESTAGSERVER_RULESET_HPP

#include <unordered_map>
#include <set>
#include "../enum/CardType.hpp"
#include "../enum/EventType.hpp"
#include "../enum/Fraction.hpp"
#include "AbstractEventTrigger.hpp"

namespace GameModel {

    class RuleSet {

        private:
            std::unordered_map<CardType, std::size_t> cardsInGame;
            std::unordered_map<Fraction, std::pair<CardType, std::size_t>> numCardsToWin;
            std::unordered_map<Fraction, std::size_t> numPlayersPerFraction;
            std::set<std::pair<std::shared_ptr<AbstractEventTrigger>, EventType>> triggerToEventMap;

        public:
            RuleSet(std::unordered_map<CardType, std::size_t> cardsInGame,
                    std::unordered_map<Fraction, std::pair<CardType, std::size_t>> numCardsToWin,
                    std::unordered_map<Fraction, std::size_t> numPlayersPerFraction,
                    std::set<std::pair<std::shared_ptr<AbstractEventTrigger>, EventType>> triggerToEventMap);

            auto getCardsInGame() const -> const std::unordered_map<CardType, std::size_t> &;

            auto getNumCardsToWin() const -> const std::unordered_map<Fraction, std::pair<CardType, std::size_t>> &;

            auto getNumPlayersPerFraction() const -> const std::unordered_map<Fraction, std::size_t> &;

            auto getTriggerToEventMap() const ->
                const std::set<std::pair<std::shared_ptr<AbstractEventTrigger>, EventType>> &;
    };
}

#endif //SECRETBUNDESTAGSERVER_RULESET_HPP
