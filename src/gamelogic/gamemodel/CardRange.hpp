/**
 * @file CardRange.hpp
 * @author bjoern
 * @date 01.12.20
 * Definition of class CardRange
 */

#ifndef SECRETBUNDESTAGSERVER_CARDRANGE_HPP
#define SECRETBUNDESTAGSERVER_CARDRANGE_HPP

#include <vector>
#include <optional>
#include <memory>
#include <stdexcept>

#include "../enum/CardType.hpp"
#include "Board.hpp"

/**
 * The namespace for the game model.
 * @namespace GameModel
 */
namespace GameModel {

    /**
     * @class CardRange
     */
    class CardRange {

        private:
            std::vector<CardType> initialState;
            std::vector<CardType> cards;
            std::vector<CardType> discarded;
            std::optional<CardType> policy;
            Board &board;
            bool applied = false;

        public:

            CardRange(Board &gameBoard, std::size_t number);

            ~CardRange();

            CardRange(const CardRange &) = delete;

            CardRange(CardRange &&) = delete;

            auto operator=(const CardRange &) -> CardRange & = delete;

            auto operator=(CardRange &&) -> CardRange & = delete;

            auto selectForPolicy(const CardType &card) -> bool;

            auto discardRemainingCards() -> bool;

            [[nodiscard]] auto discard(CardType card) -> bool;

            [[nodiscard]] auto applyToGame() -> bool;
    };
}

#endif // SECRETBUNDESTAGSERVER_CARDRANGE_HPP
