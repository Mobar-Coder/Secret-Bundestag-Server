/**
 * @file Environment.cpp
 * @author jonas
 * @date 01.12.20
 * Description here TODO
 */

#include "Environment.hpp"

#include <utility>

namespace GameModel {

    Environment::Environment(std::vector<Player> &players) : players(players) {
    }

    auto Environment::drawNCards(const std::size_t number) -> CardRange {
        std::size_t drawableCards = board.getCardPile().size();
        if (number > drawableCards) {
            throw std::runtime_error(std::string("Cannot create card range of size ") + std::to_string(number)
                                     + "! Game has only " + std::to_string(drawableCards) + " left!");
        }

        //TODO shuffle
        return CardRange(board, number);
    }

    void Environment::restockCardPile() {

    }

    // ToDo: check for >3 ?
    auto Environment::incrementElectionTracker() -> std::size_t {
        board.setElectionTracker(board.getElectionTracker() + 1);
        return board.getElectionTracker();
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
