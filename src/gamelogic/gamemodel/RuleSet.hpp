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

    /**
     * @class RuleSet
     * This class represents a set of rules and settings for a game.
     */
    class RuleSet {

        private:
            std::unordered_map<CardType, std::size_t> cardsInGame;
            std::unordered_map<Fraction, std::pair<CardType, std::size_t>> numCardsToWin;
            std::unordered_map<Fraction, std::size_t> numPlayersPerFraction;
            std::set<std::pair<std::shared_ptr<AbstractEventTrigger>, EventType>> triggerToEventMap;

        public:

            /**
             *
             * @param cardsInGame
             * @param numCardsToWin
             * @param numPlayersPerFraction
             * @param triggerToEventMap
             */
            RuleSet(std::unordered_map<CardType, std::size_t> cardsInGame,
                    std::unordered_map<Fraction, std::pair<CardType, std::size_t>> numCardsToWin,
                    std::unordered_map<Fraction, std::size_t> numPlayersPerFraction,
                    std::set<std::pair<std::shared_ptr<AbstractEventTrigger>, EventType>> triggerToEventMap);

            /**
             * Getter for cardsInGame.
             * @return
             */
            auto getCardsInGame() const -> const std::unordered_map<CardType, std::size_t> &;

            /**
             * Getter for numCardsToWin.
             * @return
             */
            auto getNumCardsToWin() const -> const std::unordered_map<Fraction, std::pair<CardType, std::size_t>> &;

            /**
             * Getter for numPlayersPerFraction.
             * @return
             */
            auto getNumPlayersPerFraction() const -> const std::unordered_map<Fraction, std::size_t> &;

            /**
             * Getter for triggerToEventMap.
             * @return
             */
            auto getTriggerToEventMap() const ->
                const std::set<std::pair<std::shared_ptr<AbstractEventTrigger>, EventType>> &;
    };
}

#endif //SECRETBUNDESTAGSERVER_RULESET_HPP
