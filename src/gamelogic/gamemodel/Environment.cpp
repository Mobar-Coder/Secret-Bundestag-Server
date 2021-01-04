/**
 * @file Environment.cpp
 * @author jonas
 * @date 01.12.20
 * Description here TODO
 */

#include "Environment.hpp"
#include "../../util/RandomGenerator.hpp"

#include <utility>
#include <random>
#include <algorithm>
#include <cassert>

namespace GameModel {

    Environment::Environment(std::vector<std::shared_ptr<Player>> players) : players(std::move(players)) {
        board.setCurrentOffice(Office::PRESIDENT, this->players[Util::rng(0, this->players.size() - 1)]);
    }

    auto Environment::getPlayers() const -> std::vector<std::shared_ptr<const Player>> {
        return std::vector<std::shared_ptr<const Player>>(players.cbegin(), players.cend());
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

    auto Environment::killPlayer(const std::shared_ptr<Player> &player) -> bool {
        auto it = std::find(players.cbegin(), players.cend(), player);
        if (it != players.cend()) {
            it->get()->setAlive(false);
            return true;
        }
        return false;
    }

    /*auto Environment::getGameState(std::shared_ptr<Player> player) -> GameStateRepresentation {
        return GameModel::GameStateRepresentation();
    }*/

    void Environment::autoSelectPresident() {
        auto player = board.getPlayerInCurrentOffice(Office::PRESIDENT);
        if (player.has_value()) {
            auto iterator_start = std::find(players.cbegin(), players.cend(), player.value());
            auto it = iterator_start;
            do {
                it++;
                if (it == players.cend()) {
                    it = players.cbegin();
                }
                if (iterator_start == it) {
                    throw std::runtime_error("All Players have been killed!");
                }
            } while (!(*it)->isAlive());
            board.setCurrentOffice(Office::PRESIDENT, *it);
        }
    }

    void Environment::resetPastOffices() {
        board.clearPastOffices();
    }

    void Environment::setCandidateForChancellor(const std::shared_ptr<Player> &player) {
        board.setCurrentOffice(Office::CANDIDATE, player);

    }

    auto Environment::electChancellor() -> bool {
        auto player = board.getPlayerInCurrentOffice(Office::CANDIDATE);
        if (player.has_value()) {
            board.setCurrentOffice(Office::CHANCELOR, player.value());
            return true;
        }
        return false;
    }

    auto Environment::getPresident() -> std::shared_ptr<const Player> {
        auto player = board.getPlayerInCurrentOffice(Office::PRESIDENT);
        assert(player.has_value());
        return player.value();
    }

    void Environment::safeToPastOffices() {
        board.safeToPastOffices();
    }

    auto Environment::getChancellor() const -> std::optional<std::shared_ptr<const Player>> {
        return board.getPlayerInCurrentOffice(Office::CHANCELOR);
    }

    auto Environment::getParty(Fraction fraction) const -> std::vector<std::shared_ptr<const Player>> {
        std::vector<std::shared_ptr<const Player>> result;
        std::copy_if(players.cbegin(), players.cend(), std::back_inserter(result),
                     [fraction](const auto &player) { return fraction == player->getFraction(); });
        return result;
    }

    auto Environment::getBoard() const -> const Board & {
        return board;
    }

    auto Environment::getNumberCardsCardPile() const -> std::size_t {
        return board.getCardPile().size();
    }

    auto Environment::getNumberCardsDiscardPile() const -> std::size_t {
        return board.getDiscardPile().size();
    }

    auto Environment::getNumberOfPlayedPolicies(CardType cardType) const -> std::size_t {
        return board.getNumberOfPolicy(cardType);
    }
}
