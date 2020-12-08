/**
 * @file CardRange.cpp
 * @author bjoern
 * @date 01.12.20
 * Description here TODO
 */

#include "CardRange.hpp"

#include <stdexcept>
#include <utility>
#include <algorithm>

namespace GameModel {
    CardRange::CardRange(std::shared_ptr<Board> gameBoard, std::size_t number) : board(std::move(gameBoard)) {
        std::size_t drawableCards = this->board->getCardPile()->size();
        if (number > drawableCards) {
            throw std::runtime_error(std::string("Cannot create card range of size ") + std::to_string(number)
                                     + "! Game has only " + std::to_string(drawableCards) + " left!");
        }

        initialState = std::vector<CardType>{board->getCardPile()->crbegin(),
                                             board->getCardPile()->crbegin() + number};
        cards = std::vector<CardType>{board->getCardPile()->crbegin(), board->getCardPile()->crbegin() + number};
        board->getCardPile()->erase(board->getCardPile()->cend() - number, board->getCardPile()->cend());
    }

    CardRange::~CardRange() {
        if (!applied) {
            for (auto it = initialState.crbegin(); it != initialState.crend(); it++) {
                board->getCardPile()->emplace_back(*it);
            }
        }
    }

    bool CardRange::selectForPolicy(const CardType &card) {
        if (policy.has_value() || applied) {
            return false;
        }

        auto result = std::find(cards.cbegin(), cards.cend(), card);
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

        auto result = std::find(cards.cbegin(), cards.cend(), card);
        if (result != cards.end()) {
            discarded.emplace_back(card);
            cards.erase(result);
            return true;
        }

        return false;
    }

    bool CardRange::applyToGame() {
        if (applied) {
            return false;
        }

        applied = true;
        if (policy.has_value()) {
            std::shared_ptr<std::unordered_map<GameModel::CardType, std::size_t>> policyStateMap = board->getPolicyState();
            policyStateMap->find(*policy)->second++;
        }

        for (const auto &card : discarded) {
            board->getDiscardPile()->emplace_back(card);
        }

        for (auto it = cards.crbegin(); it != cards.crend(); it++) {
            board->getCardPile()->emplace_back(*it);
        }

        return true;
    }
}
