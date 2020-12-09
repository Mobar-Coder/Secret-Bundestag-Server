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
                     currentOffices(std::unordered_map<Office, Player>()),
                     pastOffices(std::unordered_map<Office, Player>()),
                     cardPile(std::vector<CardType>()),
                     discardPile(std::vector<CardType>()) {
        for (int i = CardType::Fascist; i <= CardType::Liberal; i++) {
            policyState.emplace(CardType(i), 0);
        }

        //Fill CardPile with 6 liberal and 11 fascist laws
        for (int i = 0; i < NUMBER_LAWS_LIBERALS; i++) {
            cardPile.emplace_back(CardType::Liberal);
        }
        for (int i = 0; i < NUMBER_LAWS_FASCISTS; i++) {
            cardPile.emplace_back(CardType::Fascist);
        }

    }

    auto Board::getElectionTracker() const -> std::size_t {
        return electionTracker;
    }

    void Board::setElectionTracker(const std::size_t elecTracker) {
        this->electionTracker = elecTracker;
    }

    auto Board::getPolicyState() const -> const std::unordered_map<CardType, std::size_t> & {
        return policyState;
    }

    auto Board::getPolicyState() -> std::unordered_map<CardType, std::size_t> & {
        return policyState;
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
