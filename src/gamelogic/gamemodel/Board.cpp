/**
 * @file Board.cpp
 * @author jonas
 * @date 01.12.20
 * Declaration of all Board Methods
 */

#include <algorithm>
#include <search.h>
#include <random>
#include "Board.hpp"

namespace GameModel {

    Board::Board(const std::size_t numberFascistCards, const std::size_t numberLiberalCards) {

        cardPile.resize(numberLiberalCards + numberFascistCards);
        std::fill_n(cardPile.begin(), numberLiberalCards, CardType::LIBERAL);
        std::fill_n(cardPile.begin() + numberLiberalCards, numberFascistCards, CardType::FASCIST);

    }

    auto Board::getElectionTracker() const -> std::size_t {
        return electionTracker;
    }

    void Board::setElectionTracker(const std::size_t elecTracker) {
        this->electionTracker = elecTracker;
    }

    void Board::setNumberOfPolicy(CardType card, std::size_t number) {
        policyState[card] = number;
    }

    auto Board::getNumberOfPolicy(CardType card) const -> std::size_t {
        auto it = policyState.find(card);
        if (it != policyState.cend()) {
            return it->second;
        }
        return 0;
    }

    auto Board::getCurrentOffices(Office office) const -> std::optional<std::shared_ptr<const Player>> {
        auto it = currentOffices.find(office);
        if (it != currentOffices.end()) {
            return it->second;
        }
        return std::nullopt;
    }

    void Board::setCurrentOffices(Office office, const std::shared_ptr<const Player> &player) {
        currentOffices[office] = player;
    }

    auto Board::getPastOffices(Office office) const -> std::optional<std::shared_ptr<const Player>> {
        auto it = pastOffices.find(office);
        if (it != pastOffices.end()) {
            return it->second;
        }
        return std::nullopt;
    }

    auto Board::getPastOffices() -> std::unordered_map<Office, std::optional<std::shared_ptr<const Player>>> {
        return pastOffices;
    }

    void Board::setPastOffices(Office office, const std::shared_ptr<const Player> &player) {
        pastOffices[office] = player;
    }

    void Board::safeToPastOffices() {
        pastOffices = currentOffices;
    }

    auto Board::getCardPile() const -> const std::vector<CardType> & {
        return cardPile;
    }

    auto Board::getCardPile() -> std::vector<CardType> & {
        return cardPile;
    }

    auto Board::getDiscardPile() const -> const std::vector<CardType> & {
        return discardPile;
    }

    auto Board::getDiscardPile() -> std::vector<CardType> & {
        return discardPile;
    }
}
