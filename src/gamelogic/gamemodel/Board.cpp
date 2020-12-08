/**
 * @file Board.cpp
 * @author jonas
 * @date 01.12.20
 * Description here TODO
 */

#include <algorithm>
#include <search.h>
#include <random>
#include "Board.hpp"

namespace GameModel {

    Board::Board() : electionTracker(0),
                     policyState(std::make_shared<std::unordered_map<CardType, std::size_t>>()),
                     currentOffices(std::make_shared<std::unordered_map<Office, std::shared_ptr<Player>>>()),
                     pastOffices(std::make_shared<std::unordered_map<Office, std::shared_ptr<Player>>>()),
                     cardPile(std::make_shared<std::vector<CardType>>()),
                     discardPile(std::make_shared<std::vector<CardType>>()) {
    }

    auto Board::getElectionTracker() const -> std::size_t {
        return electionTracker;
    }

    void Board::setElectionTracker(std::size_t elecTracker) {
        this->electionTracker = elecTracker;
    }

    auto Board::getPolicyState() const -> std::shared_ptr<std::unordered_map<CardType, std::size_t>> {
        return policyState;
    }

    auto Board::getCurrentOffices() const -> std::shared_ptr<std::unordered_map<Office, std::shared_ptr<Player>>> {
        return currentOffices;
    }

    auto Board::getPastOffices() const -> std::shared_ptr<std::unordered_map<Office, std::shared_ptr<Player>>> {
        return pastOffices;
    }

    auto Board::getCardPile() const -> std::shared_ptr<std::vector<CardType>> {
        return cardPile;
    }

    auto Board::getDiscardPile() const -> std::shared_ptr<std::vector<CardType>> {
        return discardPile;
    }
}
