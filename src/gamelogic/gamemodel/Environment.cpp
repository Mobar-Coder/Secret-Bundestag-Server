/**
 * @file Environment.cpp
 * @author jonas
 * @date 01.12.20
 * Description here TODO
 */

#include "Environment.hpp"

#include <utility>

namespace GameModel {

    Environment::Environment(std::shared_ptr<std::vector<Player>> players) :
        board(std::make_shared<Board>()), players(std::move(players)) {
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
        board->restockCardPile();
    }

    // ToDo: check for >3 ?
    auto Environment::incrementElectionTracker() -> std::size_t {
        board->incrementElectionTracker();
        return board->getElectionTracker();
    }

    /*
    // ToDo: implement
    auto Environment::autoSelectCandidate(std::shared_ptr<Player> player) -> bool {

        return false;
    }

    // ToDo: implement
    auto Environment::electCandidate() -> bool {
        return false;
    }
    */

    // ToDo: implement
    auto Environment::resetPastOffices() -> void {

    }

    // ToDo: implement
    /*
    auto Environment::killPlayer(std::shared_ptr<Player> player) -> bool {
        return false;
    }

    // ToDo: implement
    auto Environment::getGameState(std::shared_ptr<Player> player) -> std::string {
        return std::string();
    }
    */

    // ToDo: implement
    auto Environment::setPresident() -> void  {

    }
}
