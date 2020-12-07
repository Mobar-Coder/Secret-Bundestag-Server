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

        if (number > this->board->getCardPile()->size()) {
            this->board->restockCardPile();
        }
    }

    CardRange::~CardRange() {
        // TODO: fix !!!
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
