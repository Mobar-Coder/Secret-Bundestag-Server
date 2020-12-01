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

namespace GameModel {

    class Environment {

        private:
            Board board;
            std::shared_ptr<std::vector<Player>> players;

        public:

            Environment(std::shared_ptr<std::vector<Player>> players);

            auto getPlayers() const -> std::shared_ptr<std::vector<Player>>;
            auto getBoard() const -> std::shared_ptr<Board>;

            auto drawNCards(std::size_t number) -> CardRange;
            auto restockCardPile();
            auto advanceElectionTracker() -> std::size_t;
            auto autoSelectCandidate(Player) -> bool;
            auto electCandidate() -> bool;
            auto resetPastOffices();
            auto killPlayer(Player) -> bool;
            auto getGameState(Player) -> std::string;
            auto setPresident();
    };
}


#endif // SECRETBUNDESTAGSERVER_ENVIRONMENT_HPP
