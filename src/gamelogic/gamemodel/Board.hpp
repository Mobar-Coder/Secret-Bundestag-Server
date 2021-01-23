/**
 * @file Board.hpp
 * @author jonas
 * @date 01.12.20
 * Definition of class Board
 */

#ifndef SECRETBUNDESTAGSERVER_BOARD_HPP
#define SECRETBUNDESTAGSERVER_BOARD_HPP

#include <unordered_map>
#include <vector>
#include <memory>
#include "../enum/CardType.hpp"
#include "../enum/Office.hpp"
#include "Player.hpp"

/**
 * @namespace The namespace for the game model.
 */
namespace GameModel {

    /**
     * @class The Board class represents the game board which a player would see when playing the board game version.
     */
    class Board {

        private:
            static constexpr int DEFAULT_NUMBER_FASCISTS = 11;
            static constexpr int DEFAULT_NUMBER_LIBERAL = 6;

            std::size_t electionTracker{0};
            std::unordered_map<CardType, std::size_t> policyState;
            std::unordered_map<Office, std::shared_ptr<const Player>> currentOffices;
            std::unordered_map<Office, std::shared_ptr<const Player>> pastOffices;
            // The lowest card in the pile is at position cardPile[0], so the next card for the game will be at the end
            std::vector<CardType> cardPile;
            std::vector<CardType> discardPile;

        public:

            /**
            * Main constructor for the Board class.
            */
            explicit Board(std::size_t numberFascistCards = DEFAULT_NUMBER_FASCISTS,
                           std::size_t numberLiberalCards = DEFAULT_NUMBER_LIBERAL);

            /**
            * Get the current value of the election tracker.
            * @return The current value of the election tracker as std::size_t.
            */
            [[nodiscard]] auto getElectionTracker() const -> std::size_t;

            /**
             * Sets the election tracker so a given number
             * @param electionTracker the number
             */
            void setElectionTracker(std::size_t elecTracker);

            /**
             * @param card The Cardtype which want to be known
             * @return the number of the Cards of the given Cardtype
             */
            auto getNumberOfPolicy(CardType card) const -> std::size_t;

            /**
            * Get all current offices.
            * @return The current offices as std::shared_ptr<std::unordered_map<Office, std::shared_ptr<Player>>>.
            */
            [[nodiscard]] auto
            getPlayerInCurrentOffice(Office office) const -> std::optional<std::shared_ptr<const Player>>;

            /**
             * Sets in the current offices a player to a given office
             * @param office the office to set
             * @param player the player to be set
             */
            void setCurrentOffice(Office office, const std::shared_ptr<const Player> &player);

            /**
            * Get all offices from the last played round.
            * @return The offices from the last played round as std::shared_ptr<std::unordered_map<Office, std::shared_ptr<Player>>>.
            */
            [[nodiscard]] auto
            getPlayerInPastOffice(Office office) const -> std::optional<std::shared_ptr<const Player>>;

            /**
             * Resets the past offices
             */
            void clearPastOffices();

            /**
            * Get the pile of normal cards.
            * @return The pile of normal cards as std::shared_ptr<std::vector<CardType>>.
            */
            [[nodiscard]] auto getCardPile() const -> const std::vector<CardType> &;

            [[nodiscard]] auto getCardPile() -> std::vector<CardType> &;

            /**
             * Sets the number of cards to a given policy
             * @param card the policy to set
             * @param number the number to set
             */
            void setNumberOfPolicy(CardType card, std::size_t number);

            /**
            * Get the pile of discarded cards as a const reference.
            * @return The pile of discarded cards as std::shared_ptr<std::vector<CardType>>.
            */
            [[nodiscard]] auto getDiscardPile() const -> const std::vector<CardType> &;

            /**
            * Get the pile of discarded cards as non-const reference.
            * @return The pile of discarded cards as std::shared_ptr<std::vector<CardType>>.
            */
            [[nodiscard]] auto getDiscardPile() -> std::vector<CardType> &;

            /**
             * Safes the current offices to the past offices
             */
            void safeToPastOffices();
    };
}

#endif // SECRETBUNDESTAGSERVER_BOARD_HPP
