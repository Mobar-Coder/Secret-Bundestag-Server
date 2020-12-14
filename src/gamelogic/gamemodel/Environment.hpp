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
             * @return
             */
            auto drawNCards(std::size_t number) -> CardRange;

            /**
             * Shuffles the actual Cardpile
             */
            void shuffleCardPile();

            /**
             *
             *
             * @return
             */
            auto incrementElectionTracker() -> std::size_t;

            /**
             *
             */
            auto resetElectionTracker() -> void;

            /**
              * Kill a Player.
              * @param player
              * @return
              */
            void killPlayer(const std::shared_ptr<Player> &player);

            /**
             *
             * @param player
             * @return
             */
            auto getGameState(std::shared_ptr<Player> player) -> GameStateRepresentation;

            /**
             *
             * @param player
             * @return
             */
            void autoSelectPresident();

            /**
             *
             */
            void resetPastOffices();


            /**
             *
             * @return
             */
            void setCandidateForChancelor(const std::shared_ptr<Player> &player);

            /**
             *
             * @return
             */
            auto electChancelor() -> bool;

            /**
             *
             * @return
             */
            auto getPresident() -> std::shared_ptr<const Player>;

            /**
             *
             */
            void safeToPastOffices();

            /**
             *
             * @return
             */
            auto getChancelor() const -> std::optional<std::shared_ptr<const Player>>;

            /**
             *
             * @param fraction
             * @return
             */
            auto getParty(Fraction fraction) const -> std::vector<std::shared_ptr<const Player>>;

        private:
            /**
             *
             *
             */
            void restockCardPile();


    };
}


#endif // SECRETBUNDESTAGSERVER_ENVIRONMENT_HPP
