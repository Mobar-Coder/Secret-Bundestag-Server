/**
 * @file RuleSet.hpp
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

/**
 * @namespace GameModel
 * The namespace for the game model.
 */
namespace GameModel {

    using cardsInGame_t = std::unordered_map<CardType, std::size_t>;
    using numCardsToWin_t = std::unordered_map<Fraction, std::pair<CardType, std::size_t>>;
    using numPlayersPerFraction_t = std::unordered_map<Fraction, std::size_t>;
    using triggerToEventMap_t = std::set<std::pair<std::shared_ptr<AbstractEventTrigger>, EventType>>;

    /**
     * @class RuleSet
     * This class represents a set of rules and settings for a game.
     */
    class RuleSet {

        private:
            cardsInGame_t cardsInGame;
            numCardsToWin_t numCardsToWin;
            std::unordered_map<Fraction, std::size_t> numPlayersPerFraction;
            triggerToEventMap_t triggerToEventMap;

        public:

            /**
             *
             * @param cardsInGame
             * @param numCardsToWin
             * @param numPlayersPerFraction
             * @param triggerToEventMap
             */
            RuleSet(cardsInGame_t cardsInGame, numCardsToWin_t numCardsToWin,
                    numPlayersPerFraction_t numPlayersPerFraction, triggerToEventMap_t triggerToEventMap);

            /**
             * Getter for cardsInGame.
             * @return
             */
            auto getCardsInGame() const -> const cardsInGame_t &;

            /**
             * Getter for numCardsToWin.
             * @return
             */
            auto getNumCardsToWin() const -> const numCardsToWin_t &;

            /**
             * Getter for numPlayersPerFraction.
             * @return
             */
            auto getNumPlayersPerFraction() const -> const numPlayersPerFraction_t &;

            /**
             * Getter for triggerToEventMap.
             * @return
             */
            auto getTriggerToEventMap() const -> const triggerToEventMap_t &;
    };
}

#endif //SECRETBUNDESTAGSERVER_RULESET_HPP
