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
             * Get the game board.
             * @return The game board as std::shared_ptr<Board>.
             */
            [[nodiscard]] auto getBoard() const -> std::shared_ptr<Board>;

            /**
             * Draw N cards from the normal card pile.
             * @param number
             * @return
             */
            auto drawNCards(std::size_t number) -> CardRange;

            /**
             *
             * ToDo: Wir des benötigt, dass die Funktion nach außen geführt wird? Reicht es nicht im Board?
             */
            auto restockCardPile() -> void;

            /**
             *
             * ToDo: Wir des benötigt, dass die Funktion nach außen geführt wird? Reicht es nicht im Board?
             * @return
             */
            auto incrementElectionTracker() -> std::size_t;

            /**
             *
             * ToDo: Was soll das tun? Mit dieser signatur ergibt das doch keinen Sinn oder verseth ich das falsch?
             * @param player
             * @return
             */
            auto autoSelectCandidate(std::shared_ptr<Player> player) -> bool;

            /**
             *
             * ToDo: Dazu braucht man eine object in dem der Kandidat hinterlegt ist.
             * @return
             */
            auto electCandidate() -> bool;

            /**
             *
             */
            auto resetPastOffices() -> void ;

            /**
             * Kill a Player.
             * ToDo: Braucht man das hier wirklicht? Warum nicht gleich das Flag im Player setzen?
             * @param player
             * @return
             */
            auto killPlayer(std::shared_ptr<Player> player) -> bool;

            /**
             *
             * ToDo: Was soll hier nochmal zurück gegeben werden?
             * @param player
             * @return
             */
            auto getGameState(std::shared_ptr<Player> player) -> std::string;

            /**
             *
             * ToDo; Warum nur "setPresident" und nicht set Role, das wäre doch universaler oder nicht?
             */
            auto setPresident() -> void;
    };
}


#endif // SECRETBUNDESTAGSERVER_ENVIRONMENT_HPP
