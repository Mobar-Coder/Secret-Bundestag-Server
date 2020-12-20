/**
 * @file RuleSet.cpp.c
 * @author jonas
 * @date 14.12.20
 * Description here TODO
 */

#include "RuleSet.hpp"

#include <utility>

namespace GameModel  {

    RuleSet::RuleSet(cardsInGame_t cardsInGame, numCardsToWin_t numCardsToWin,
                     numPlayersPerFraction_t numPlayersPerFraction, triggerToEventMap_t triggerToEventMap) :
                        cardsInGame(std::move(cardsInGame)), numCardsToWin(std::move(numCardsToWin)),
                        numPlayersPerFraction(std::move(numPlayersPerFraction)),
                        triggerToEventMap(std::move(triggerToEventMap)) {
    }

    auto RuleSet::getCardsInGame() const -> const cardsInGame_t & {
        return cardsInGame;
    }

    auto RuleSet::getNumCardsToWin() const -> const numCardsToWin_t & {
        return numCardsToWin;
    }

    auto RuleSet::getNumPlayersPerFraction() const -> const numPlayersPerFraction_t & {
        return numPlayersPerFraction;
    }

    auto RuleSet::getTriggerToEventMap() const -> const triggerToEventMap_t & {
        return triggerToEventMap;
    }
}
