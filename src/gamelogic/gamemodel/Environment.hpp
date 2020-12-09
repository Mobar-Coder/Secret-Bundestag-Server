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
        std::shared_ptr<Board> board;
        std::shared_ptr<std::vector<Player>> players;

    public:

        /**
         * Main constructor for the Environment class.
         * @param players
         */
        explicit Environment(std::shared_ptr<std::vector<Player>> players);

        /**
         * Get all players.
         * @return All Players as std::shared_ptr<std::vector<Player>>.
         */
        [[nodiscard]] auto getPlayers() const -> std::shared_ptr<std::vector<Player>>;

        /**
         * //TODO schreiben
         * @developer Bjoern
         * Draw N cards from the normal card pile., Must be sure, that n cards can be drawn otherwise exception or restock....
         * @param number
         * @return
         */
        auto drawNCards(std::size_t number) -> CardRange;

        /**
         *
         *
         */
        void restockCardPile();

        /**
         *
         *
         * @return
         */
        auto incrementElectionTracker() -> std::size_t;

        /**
         *
         */
        bool resetElectionTracker();

        /**
         *
         * @param player
         * @return
         */
        bool autoSelectPresident();

        /**
         *
         */
        bool safePastOffices();

        /**
         *
         */
        bool resetPastOffices();

        /**
         * Kill a Player.
         * @param player
         * @return
         */
        bool killPlayer(std::shared_ptr<Player> player);

        /**
         *
         * ToDo: Was soll hier nochmal zurück gegeben werden?
         * @param player
         * @return
         */
        auto getGameState(std::shared_ptr<Player> player) -> GameStateRepresentation;


        /**
         *
         * @return
         */
        bool setCandidateForChancelor(std::shared_ptr<Player> player);

        /**
         *
         * @return
         */
        bool electChancelor();

        /**
         *
         * @return
         */
        auto getPresident() -> std::shared_ptr<Player>;

        /**
         *
         * @return
         */
        auto getChancelor() -> std::shared_ptr<Player>;

        /**
         *
         * @param fraction
         * @return
         */
        auto getParty(Fraction fraction) -> std::vector<std::shared_ptr<Player>>;


    };
}


#endif // SECRETBUNDESTAGSERVER_ENVIRONMENT_HPP
