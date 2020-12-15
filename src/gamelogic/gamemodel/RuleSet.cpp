/**
 * @file RuleSet.cpp.c
 * @author jonas
 * @date 14.12.20
 * Description here TODO
 */

#include "RuleSet.hpp"

#include <utility>

namespace GameModel  {

    RuleSet::RuleSet(std::unordered_map<CardType, std::size_t> cardsInGame,
                        std::unordered_map<Fraction, std::pair<CardType, std::size_t>> numCardsToWin,
                        std::unordered_map<Fraction, std::size_t> numPlayersPerFraction,
                        std::set<std::pair<std::shared_ptr<AbstractEventTrigger>, EventType>> triggerToEventMap) :
                        cardsInGame(std::move(cardsInGame)), numCardsToWin(std::move(numCardsToWin)),
                        numPlayersPerFraction(std::move(numPlayersPerFraction)),
                        triggerToEventMap(std::move(triggerToEventMap)) {
    }

    auto RuleSet::getCardsInGame() const -> const std::unordered_map<CardType, std::size_t> & {
        return cardsInGame;
    }

    auto RuleSet::getNumCardsToWin() const -> const std::unordered_map<Fraction, std::pair<CardType, std::size_t>> & {
        return numCardsToWin;
    }

    auto RuleSet::getNumPlayersPerFraction() const -> const std::unordered_map<Fraction, std::size_t> & {
        return numPlayersPerFraction;
    }

    auto RuleSet::getTriggerToEventMap() const ->
        const std::set<std::pair<std::shared_ptr<AbstractEventTrigger>, EventType>> & {
        return triggerToEventMap;
    }
}
