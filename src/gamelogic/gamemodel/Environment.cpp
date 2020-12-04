/**
 * @file Environment.cpp
 * @author jonas
 * @date 01.12.20
 * Description here TODO
 */

#include "Environment.hpp"

#include <utility>

namespace GameModel {

    Environment::Environment(std::shared_ptr<std::vector<Player>> players) : board(std::make_shared<Board>()), players(std::move(players) {
        this->players = std::move(players);
    }

    auto Environment::getPlayers() const -> std::shared_ptr<std::vector<Player>> {
        return players;
    }

    auto Environment::getBoard() const -> std::shared_ptr<Board> {
        return board;
    }

    auto Environment::drawNCards(std::size_t number) -> CardRange {
        return CardRange(board, number);
    }

    auto Environment::restockCardPile() -> void {

    }

    auto Environment::incrementElectionTracker() -> std::size_t {
        board->incrementElectionTracker();
        return board->getElectionTracker();
    }

    /*
    auto Environment::autoSelectCandidate(std::shared_ptr<Player> player) -> bool {

        return false;
    }

    auto Environment::electCandidate() -> bool {
        return false;
    }
    */

    auto Environment::resetPastOffices() -> void {

    }

    /*
    auto Environment::killPlayer(std::shared_ptr<Player> player) -> bool {
        return false;
    }

    auto Environment::getGameState(std::shared_ptr<Player> player) -> std::string {
        return std::string();
    }
    */

    auto Environment::setPresident() -> void  {

    }
}
