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

    Environment::Environment(std::vector<std::shared_ptr<Player>> players) : players(std::move(players)) {
        shuffleCardPile();
    }

    auto Environment::getPlayers() const -> std::vector<std::shared_ptr<const Player>> {
        return std::vector<std::shared_ptr<const Player>>(players.begin(), players.end());
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

    void Environment::resetElectionTracker() {
        board.setElectionTracker(0);
    }

    void Environment::killPlayer(const std::shared_ptr<Player> &player) {
        player->setAlive(false);
    }

    /*auto Environment::getGameState(std::shared_ptr<Player> player) -> GameStateRepresentation {
        return GameModel::GameStateRepresentation();
    }*/

    void Environment::autoSelectPresident() {
        auto player = board.getCurrentOffices(Office::PRESIDENT);
        if (player.has_value()) {
            //TODO: Endlosschleife!!!!!
            auto it = std::find(players.cbegin(), players.cend(), player.value());
            do {
                it++;
                if (it == players.cend()) {
                    it = players.cbegin();
                }
            } while ((*it)->isAlive());
            board.setCurrentOffices(Office::PRESIDENT, *it);
        }
    }

    void Environment::resetPastOffices() {
        board.getPastOffices().clear();
    }

    void Environment::setCandidateForChancelor(const std::shared_ptr<Player> &player) {
        board.setCurrentOffices(Office::CANDIDATE, player);

    }

    auto Environment::electChancelor() -> bool {
        auto player = board.getCurrentOffices(Office::CANDIDATE);
        if (player.has_value()) {
            board.setCurrentOffices(Office::CHANCELOR, player.value());
            return true;
        }
        return false;
    }

    auto Environment::getPresident() -> std::shared_ptr<const Player> {
        auto player = board.getCurrentOffices(Office::PRESIDENT);
        if (player.has_value()) {
            return player.value();
        }
        throw std::runtime_error("No President is elected!!!");
    }

    void Environment::safeToPastOffices() {
        board.safeToPastOffices();
    }

    auto Environment::getChancelor() const -> std::optional<std::shared_ptr<const Player>> {
        return board.getCurrentOffices(Office::CHANCELOR);
    }

    auto Environment::getParty(Fraction fraction) const -> std::vector<std::shared_ptr<const Player>> {
        std::vector<std::shared_ptr<const Player>> result;
        for (const auto &player : players) {
            if (player->getFraction() == fraction) {
                result.emplace_back(player);
            }
        }
        return result;
    }
}
