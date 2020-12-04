/**
 * @file CardRange.hpp
 * @author bjoern
 * @date 01.12.20
 * Description here TODO
 */

#ifndef SECRETBUNDESTAGSERVER_CARDRANGE_HPP
#define SECRETBUNDESTAGSERVER_CARDRANGE_HPP

#include <vector>
#include <optional>
#include <memory>

#include "../enum/CardType.hpp"
#include "Board.hpp"

namespace GameModel {
    class CardRange {

        public:
            CardRange(const CardRange &) = delete;
            CardRange(std::shared_ptr<Board>  board, unsigned int n);
            ~CardRange();

            CardRange &operator=(const CardRange &) = delete;
            [[nodiscard]] bool selectForPolicy( CardType cardType) const;
            [[nodiscard]] bool discard(CardType cardType) const;
            [[nodiscard]] bool applyToGame() const;

        private:
            std::vector<CardType> initialState;
            std::vector<CardType> cards;
            std::vector<CardType> discarded;
            std::optional<CardType> policy;
            std::shared_ptr<Board> board;
            bool applied;
    };

}

#endif // SECRETBUNDESTAGSERVER_CARDRANGE_HPP
