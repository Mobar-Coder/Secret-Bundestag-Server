/**
 * @file Board.hpp
 * @author jonas
 * @date 01.12.20
 * Description here TODO
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

            std::size_t electionTracker;
            std::shared_ptr<std::unordered_map<CardType, std::size_t>> policyState;
            std::shared_ptr<std::unordered_map<Office, std::shared_ptr<Player>>> currentOffices;
            std::shared_ptr<std::unordered_map<Office, std::shared_ptr<Player>>> pastOffices;
            std::shared_ptr<std::vector<CardType>> cardPile;
            std::shared_ptr<std::vector<CardType>> discardPile;

        public:

            /**
            * Main constructor for the Board class.
            */
            Board();

            /**
            * Get the current value of the election tracker.
            * @return The current value of the election tracker as std::size_t.
            */
            [[nodiscard]] auto getElectionTracker() const -> std::size_t;

            /**
            * Get the current policy state, aka. all played cards.
            * @return The current policy state as std::shared_ptr<std::unordered_map<CardType, std::size_t>>.
            */
            [[nodiscard]] auto getPolicyState() const -> std::shared_ptr<std::unordered_map<CardType, std::size_t>>;

            /**
            * Get all current offices.
            * @return The current offices as std::shared_ptr<std::unordered_map<Office, std::shared_ptr<Player>>>.
            */
            [[nodiscard]] auto getCurrentOffices() const ->
                std::shared_ptr<std::unordered_map<Office, std::shared_ptr<Player>>>;

            /**
            * Get all offices from the last played round.
            * @return The offices from the last played round as std::shared_ptr<std::unordered_map<Office, std::shared_ptr<Player>>>.
            */
            [[nodiscard]] auto getPastOffices() const ->
                std::shared_ptr<std::unordered_map<Office, std::shared_ptr<Player>>>;

            /**
            * Get the pile of normal cards.
            * @return The pile of normal cards as std::shared_ptr<std::vector<CardType>>.
            */
            [[nodiscard]] auto getCardPile() const -> std::shared_ptr<std::vector<CardType>>;

            /**
            * Get the pile of discarded cards.
            * @return The pile of discarded cards as std::shared_ptr<std::vector<CardType>>.
            */
            [[nodiscard]] auto getDiscardPile() const -> std::shared_ptr<std::vector<CardType>>;

            /**
            * Push a card the the current policy state.
            * @param cardType
            * @param policyNumber
            */
            auto pushToPolicyState(CardType cardType, std::size_t policyNumber) -> void;

            /**
            * Increment the election tracker by one.
            */
            auto incrementElectionTracker() -> void;

            /**
            * Reset the election tracker back to 0.
            */
            auto resetElectionTracker() -> void;

            /**
            * Copy all player office pairs from the current office to the past offices.
            */
            auto copyCurrentOfficesToPastOffices() -> void;

            /**
            * Add a player office pair to the current offices.
            * @param office
            * @param player
            * @return True on success, else false.
            */
            auto addToCurrentOffices(Office office, std::shared_ptr<Player> player) -> bool;

            /**
            * Remove a player office pair from the current offices.
            * @param office
            * @return True on success, else false,.
            */
            auto removeFromCurrentOffices(Office office) -> bool;

            /**
            * Emplace a card back to the pile of normal cards.
            * @param cardType
            */
            auto emplaceBackToCardPile(CardType cardType) -> void;

            /**
            * Emplace a card back to the pile of discarded cards.
            * @param cardType
            */
            auto emplaceBackToDiscardPile(CardType cardType) -> void;

            /**
            * Shuffle the pile of discarded cards and puts the cards at the end of the normal card pile.
            */
            auto restockCardPile() -> void;
    };
}

#endif // SECRETBUNDESTAGSERVER_BOARD_HPP
