/**
 * @file Environment.cpp
 * @author jonas
 * @date 01.12.20
 * Description here TODO
 */

#include "Environment.hpp"

namespace GameModel {

    Environment::Environment(std::shared_ptr<std::vector<Player>> players) {
        this->players = players;
    }

    auto Environment::getPlayers() const -> std::shared_ptr<std::vector<Player>> {
        return this->players;
    }

    auto Environment::getBoard() const -> std::shared_ptr<Board> {
        return std::make_shared<Board>(this->board);
    }


    auto Environment::restockCardPile() {
        return nullptr;
    }

    auto Environment::advanceElectionTracker() -> std::size_t {
        return 0;
    }

    /*
    auto Environment::drawNCards(std::size_t number) -> CardRange {
        return nullptr;
    }*/

    auto Environment::autoSelectCandidate(Player) -> bool {
        return false;
    }

    auto Environment::electCandidate() -> bool {
        return false;
    }

    auto Environment::resetPastOffices() {
        return nullptr;
    }

    auto Environment::killPlayer(Player) -> bool {
        return false;
    }

    auto Environment::getGameState(Player) -> std::string {
        return std::string();
    }

    auto Environment::setPresident() {
        return nullptr;
    }
}
