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

    private:
        const std::vector<CardType> initialState;
        std::vector<CardType> cards;
        std::vector<CardType> discarded;
        std::optional<CardType> policy;
        Board &board;
        bool applied = false;

    public:

        CardRange(Board &board, std::size_t number);

        ~CardRange();

        CardRange(const CardRange &) = delete;

        CardRange &operator=(const CardRange &) = delete;

        CardRange &operator=(CardRange &&) = delete;

        bool selectForPolicy(const CardType &cardType);

        [[nodiscard]] bool discard(CardType cardType);

        [[nodiscard]] bool applyToGame();
    };
}

#endif // SECRETBUNDESTAGSERVER_CARDRANGE_HPP
