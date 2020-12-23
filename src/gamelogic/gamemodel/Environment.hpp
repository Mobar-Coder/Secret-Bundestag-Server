/**
 * @file Environment.hpp
 * @author jonas
 * @date 01.12.20
 * Description here TODO
 */

#ifndef SECRETBUNDESTAGSERVER_ENVIRONMENT_HPP
#define SECRETBUNDESTAGSERVER_ENVIRONMENT_HPP

#include <vector>
#include "Board.hpp"
#include "CardRange.hpp"
#include "Player.hpp"
#include "GameStateRepresentation.hpp"

/**
 * @namespace The namespace for the game model.
 */
namespace GameModel {

    /**
     * @class The environment class represents the whole game environment containing all game objects and entities.
     */
    class Environment {

        private:
            Board board{};
            const std::vector<std::shared_ptr<Player>> players;

        public:

            /**
             * Main constructor for the Environment class.
             * @param players
             */
            explicit Environment(std::vector<std::shared_ptr<Player>> players);

            /**
             * Get all players.
             * @return All Players as std::shared_ptr<std::vector<Player>>.
             */
            [[nodiscard]] auto getPlayers() const -> std::vector<std::shared_ptr<const Player>>;

            /**
             * @developer Bjoern
             * Draw N cards from the normal card pile.
             * @param number
             * @return A Cardrange with the given cards
             */
            auto drawNCards(std::size_t number) -> CardRange;

            /**
             * Shuffles the actual Cardpile
             */
            void shuffleCardPile();

            /**
             * increment the election tracker by one
             * @return the current value of the election tracker
             */
            auto incrementElectionTracker() -> std::size_t;

            /**
             * resets the election tracker to zero
             */
            void resetElectionTracker();

            /**
              * Kill a Player.
              * @param player to kill
              */
            void killPlayer(const std::shared_ptr<Player> &player);

            /**
             * //TODO
             * @param player
             * @return
             */
            auto getGameState(std::shared_ptr<Player> player) -> GameStateRepresentation;

            /**
             * selects automatically the next president in the vector of players, fails if all players are dead
             */
            void autoSelectPresident();

            /**
             * reset the whole past offices
             */
            void resetPastOffices();


            /**
             * set the given player as candidate for chancellor
             */
            void setCandidateForChancellor(const std::shared_ptr<Player> &player);

            /**
             * elect the chancellor candidate, but there must be a candidate
             * @return true if success
             */
            auto electChancellor() -> bool;

            /**
             * returns the actual president
             * @return shared_ptr to the player which is president
             */
            auto getPresident() -> std::shared_ptr<const Player>;

            /**
             * safe the current offices to the past offices
             */
            void safeToPastOffices();

            /**
             * return the actual chancellor
             * @return is an optional, if no chancellor is not elected
             */
            auto getChancellor() const -> std::optional<std::shared_ptr<const Player>>;

            /**
             * delivers all player of a party
             * @param fraction we want to have the players
             * @return a vector of the searched players
             */
            auto getParty(Fraction fraction) const -> std::vector<std::shared_ptr<const Player>>;

            /**
             * The number of cards in the non-discarded card pile
             * @return number
             */
            auto getNumberCardsCardPile() const -> std::size_t;

            /**
             * The number of cards in the discarded card pile
             * @return number
             */
            auto getNumberCardsDiscardPile() const -> std::size_t;

            /**
             * Get the number of played policies of a certain type.
             * @param cardType
             * @return
             */
            auto getNumberOfPlayedPolicies(CardType cardType) const -> std::size_t;

        protected:
            /**
             * Return a reference to the actual Board, is only needed for testing
             * @return reference to board
             */
            auto getBoard() const -> const Board &;

        private:
            /**
             * restock the card pile from the discarded card pile
             */
            void restockCardPile();


    };
}


#endif // SECRETBUNDESTAGSERVER_ENVIRONMENT_HPP
