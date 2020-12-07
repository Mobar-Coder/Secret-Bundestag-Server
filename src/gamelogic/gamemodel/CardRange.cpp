/**
 * @file CardRange.cpp
 * @author bjoern
 * @date 01.12.20
 * Description here TODO
 */

#include "CardRange.hpp"

#include <stdexcept>
#include <utility>

namespace GameModel {
    CardRange::CardRange(std::shared_ptr<Board> board, std::size_t number) : board(std::move(board)) {
        std::size_t drawableCards = this->board->getCardPile()->size();
        if (number > drawableCards) {
            throw std::runtime_error(std::string("Cannot create card range of size ") + std::to_string(number)
                                     + "! Game has only " + std::to_string(drawableCards) + " left!");
        }

        initialState = std::vector<CardType>(board->getCardPile()->rbegin(),
                                             board->getCardPile()->rbegin() + number);
        cards = std::vector<CardType>(board->getCardPile()->rbegin(), board->getCardPile()->rbegin() + number);
        board->getCardPile()->erase(board->getCardPile()->end(), board->getCardPile()->end() - number);
    }

    CardRange::~CardRange() {
        if (!applied) {
            for (auto it = initialState.rbegin(); it != initialState.rend(); it++) {
                board->getCardPile()->emplace_back(*it);
            }
        }
    }

    bool CardRange::selectForPolicy(const CardType card) {
        if (policy.has_value() || applied) {
            return false;
        }

        auto result = std::find(cards.begin(), cards.end(), card);
        if (result != cards.end()) {
            policy.emplace(card);
            cards.erase(result);
            return true;
        }

        return false;
    }

    bool CardRange::discard(const CardType card) {
        if (applied) {
            return false;
        }

        auto result = std::find(cards.begin(), cards.end(), card);
        if (result != cards.end()) {
            discarded.emplace_back(card);
            cards.erase(result);
        }

        return false;
    }

    bool CardRange::applyToGame() {
        if (applied) {
            return false;
        }

        applied = true;
        if (policy.has_value()) {
            board->getPolicyState()->find(*policy)->second++;
        }

        for (const auto &card : discarded) {
            board->getDiscardPile()->emplace_back(card);
        }

        for (auto it = cards.rbegin(); it != cards.rend(); it++) {
            board->getCardPile()->emplace_back(*it);
        }

        return true;
    }
}
