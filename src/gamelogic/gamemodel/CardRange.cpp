/**
 * @file CardRange.cpp
 * @author bjoern
 * @date 01.12.20
 * Declaration of all CardRange Methods
 */

#include "CardRange.hpp"

#include <utility>
#include <algorithm>

namespace GameModel {
    CardRange::CardRange(Board &gameBoard, const std::size_t number) : board(gameBoard) {
        std::size_t drawableCards = board.getCardPile().size() + board.getDiscardPile().size();
        if (number > drawableCards) {
            throw std::runtime_error("Cannot create card range of size " + std::to_string(number)
                                     + "! Game has only " + std::to_string(drawableCards) + " cards!");
        }

        initialState = std::vector<CardType>(gameBoard.getCardPile().crbegin(),
                                             gameBoard.getCardPile().crbegin() + number);
        cards = std::vector<CardType>(board.getCardPile().crbegin(), board.getCardPile().crbegin() + number);
        board.getCardPile().erase(board.getCardPile().cend() - number, board.getCardPile().cend());
    }

    CardRange::~CardRange() {
        if (!applied) {
            for (auto it = initialState.crbegin(); it != initialState.crend(); it++) {
                board.getCardPile().emplace_back(*it);
            }
        }
    }

    auto CardRange::selectForPolicy(const CardType &card) -> bool {
        if (policy.has_value() || applied) {
            return false;
        }

        auto result = std::find(cards.cbegin(), cards.cend(), card);
        if (result != cards.end()) {
            policy.emplace(card);
            discarded.emplace_back(card);
            cards.erase(result);
            return true;
        }

        return false;
    }

    auto CardRange::discardRemainingCards() -> bool {
        if (applied) {
            return false;
        }

        for (auto rest : cards) { //NOLINT
            if (!discard(rest)) {
                return false;
            }
        }
        return true;
    }

    auto CardRange::discard(const CardType card) -> bool {
        if (applied) {
            return false;
        }

        auto result = std::find(cards.cbegin(), cards.cend(), card);
        if (result != cards.end()) {
            discarded.emplace_back(card);
            cards.erase(result);
            return true;
        }

        return false;
    }

    auto CardRange::applyToGame() -> bool {
        if (applied) {
            return false;
        }

        applied = true;
        if (policy.has_value()) {
            board.setNumberOfPolicy(*policy, board.getNumberOfPolicy(*policy) + 1);
        }

        for (auto card : discarded) {
            board.getDiscardPile().emplace_back(card);
        }

        for (auto it = cards.crbegin(); it != cards.crend(); it++) {
            board.getCardPile().emplace_back(*it);
        }

        return true;
    }
}
