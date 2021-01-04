/**
 * @file Environment.cpp
 * @author jonas
 * @date 01.12.20
 * Description here TODO
 */

#include "Environment.hpp"

#include <utility>
#include <random>
#include <algorithm>

namespace GameModel {

    Environment::Environment(const int *players) : players(players) {
        shuffleCardPile();
    }

    auto Environment::drawNCards(const std::size_t number) -> CardRange {

        if (number > board.getCardPile().size()) {
            restockCardPile();
        }

        return CardRange(board, number);
    }

    void Environment::restockCardPile() {
        board.getCardPile().insert(board.getCardPile().cend(), board.getDiscardPile().cbegin(),
                                   board.getDiscardPile().cend());
        board.getDiscardPile().clear();
        shuffleCardPile();
    }

    void Environment::shuffleCardPile() {
        auto rd = std::random_device{};
        auto rng = std::default_random_engine{rd()};
        std::shuffle(board.getCardPile().begin(), board.getCardPile().end(), rng);
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
    auto Environment::resetPastOffices() -> void {

    }

    auto Environment::getPlayers() const -> const std::vector<Player> & {
        return players;
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

    auto Environment::getNumberOfPlayedPolicies(CardType cardType) const -> std::size_t {
        return board.getNumberOfPolicy(cardType);
    }
}
