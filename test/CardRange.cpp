//
// Created by bjorn on 07.12.20.
//

#include <gtest/gtest.h>
#include "src/gamelogic/gamemodel/CardRange.hpp"

TEST(card_range_test, select_policy) {
    std::shared_ptr<GameModel::Board> board = std::make_shared<GameModel::Board>(GameModel::Board{});
    board->getCardPile()->emplace_back(GameModel::CardType::Fascist);
    board->getCardPile()->emplace_back(GameModel::CardType::Fascist);
    board->getCardPile()->emplace_back(GameModel::CardType::Liberal);
    board->getCardPile()->emplace_back(GameModel::CardType::Liberal);

    GameModel::CardRange cardRange{board, 3};
    EXPECT_TRUE(cardRange.selectForPolicy(GameModel::CardType::Liberal));
}