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

    auto Environment::drawNCards(std::size_t number) -> CardRange {
        return CardRange(*board, number);
    }

    void Environment::restockCardPile() {

    }

    // ToDo: check for >3 ?
    auto Environment::incrementElectionTracker() -> std::size_t {
        board->setElectionTracker(board->getElectionTracker() + 1);
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
    bool Environment::resetPastOffices() {

        return false;
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
}
