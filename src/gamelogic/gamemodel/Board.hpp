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
            static constexpr int DEFAULTNUMBERFASCISTS = 11;
            static constexpr int DEFAULTNUMBERLIBERAL = 6;

            std::size_t electionTracker{0};
            std::unordered_map<CardType, std::size_t> policyState;
            std::unordered_map<Office, Player> currentOffices;
            std::unordered_map<Office, Player> pastOffices;
            // The lowest card in the pile is at position cardPile[0], so the next card for the game will be at the end
            std::vector<CardType> cardPile;
            std::vector<CardType> discardPile;

        public:

            /**
            * Main constructor for the Board class.
            */
            explicit Board(std::size_t numberFascistCards = DEFAULTNUMBERFASCISTS,
                           std::size_t numberLiberalCards = DEFAULTNUMBERLIBERAL);

            /**
            * Get the current value of the election tracker.
            * @return The current value of the election tracker as std::size_t.
            */
            [[nodiscard]] auto getElectionTracker() const -> std::size_t;

            /**
             *
             * @param electionTracker
             */
            void setElectionTracker(std::size_t elecTracker);

            /**
             *
             * @param card
             * @return
             */
            auto getNumberOfPolicy(CardType card) const -> std::size_t;

            /**
            * Get all current offices.
            * @return The current offices as std::shared_ptr<std::unordered_map<Office, std::shared_ptr<Player>>>.
            */
            [[nodiscard]] auto getCurrentOffices() const -> const std::unordered_map<Office, Player> &;

            /**
            * Get all offices from the last played round.
            * @return The offices from the last played round as std::shared_ptr<std::unordered_map<Office, std::shared_ptr<Player>>>.
            */
            [[nodiscard]] auto getPastOffices() const -> const std::unordered_map<Office, Player> &;

            /**
            * Get the pile of normal cards.
            * @return The pile of normal cards as std::shared_ptr<std::vector<CardType>>.
            */
            [[nodiscard]] auto getCardPile() const -> const std::vector<CardType> &;

            [[nodiscard]] auto getCardPile() -> std::vector<CardType> &;

            /**
             *
             * @param card
             * @param number
             */
            void setNumberOfPolicy(CardType card, std::size_t number);

            /**
            * Get the pile of discarded cards.
            * @return The pile of discarded cards as std::shared_ptr<std::vector<CardType>>.
            */
            [[nodiscard]] auto getDiscardPile() const -> const std::vector<CardType> &;

            /**
             *
             * @return
             */
            [[nodiscard]] auto getDiscardPile() -> std::vector<CardType> &;

            /**
             *
             */
            friend class CardRange;
    };
}

#endif // SECRETBUNDESTAGSERVER_BOARD_HPP
