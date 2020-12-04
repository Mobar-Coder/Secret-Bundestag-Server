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
            std::shared_ptr<Board> board;
            std::shared_ptr<std::vector<Player>> players;

        public:

            explicit Environment(std::shared_ptr<std::vector<Player>> players);

            [[nodiscard]] auto getPlayers() const -> std::shared_ptr<std::vector<Player>>;
            [[nodiscard]] auto getBoard() const -> std::shared_ptr<Board>;

            auto drawNCards(std::size_t number) -> CardRange;
            auto restockCardPile() -> void;
            auto incrementElectionTracker() -> std::size_t;
            auto autoSelectCandidate(std::shared_ptr<Player> player) -> bool;
            auto electCandidate() -> bool;
            auto resetPastOffices() -> void ;
            auto killPlayer(std::shared_ptr<Player> player) -> bool;
            auto getGameState(std::shared_ptr<Player> player) -> std::string;
            auto setPresident() -> void;
    };
}


#endif // SECRETBUNDESTAGSERVER_ENVIRONMENT_HPP
