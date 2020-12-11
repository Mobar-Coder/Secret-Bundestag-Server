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

    Board::Board(const std::size_t numberFascistCards, const std::size_t numberLiberalCards) {

        //TODO std::fill_n
        for (std::size_t i = 0; i < numberLiberalCards; i++) {
            cardPile.emplace_back(CardType::Liberal);
        }
        for (std::size_t i = 0; i < numberFascistCards; i++) {
            cardPile.emplace_back(CardType::Fascist);
        }

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
        if(it != policyState.cend()){
            return it->second;
        }
        return 0;
    }

    auto Board::getCurrentOffices() const -> const std::unordered_map<Office, Player> & {
        return currentOffices;
    }

    auto Board::getPastOffices() const -> const std::unordered_map<Office, Player> & {
        return pastOffices;
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
