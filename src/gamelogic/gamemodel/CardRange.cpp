/**
 * @file CardRange.cpp
 * @author bjoern
 * @date 01.12.20
 * Description here TODO
 */

#include "CardRange.hpp"

#include <utility>

namespace GameModel {
    CardRange::CardRange(std::shared_ptr<Board> board, unsigned int n) : board(std::move(board)) {
        std::size_t drawableCards = this->board->getCardPile().size();
        if (n > drawableCards) {
            throw std::runtime_error(std::string("Cannot create card range of size ") + std::to_string(n)
                                     + "! Game has only " + std::to_string(drawableCards) + " left!");
        }

        if (n > this->board->getCardPile().size()) {
            //TODO this->board.restock....
        }
    }

    CardRange::~CardRange() {
        if (!applied) {
            for (const auto &element : initialState) {
                this->board->cardPileEmplaceBack(element);
            }
        }
    }

    bool CardRange::selectForPolicy(const CardType cardType) const {
        if(policy.has_value() || applied){
            return false;
        }
        //TODO
        if (cardType == CardType::Fascist) {
            return true;
        }
        return false;
    }

    bool CardRange::discard(const CardType cardType) const {
        //TODO
        if (cardType == CardType::Fascist) {
            return true;
        }
        return false;
    }

    bool CardRange::applyToGame() const{
        //TODO
        return false;
    }
}
