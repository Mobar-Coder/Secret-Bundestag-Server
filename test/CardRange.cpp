//
// Created by bjorn on 07.12.20.
//

#include <gtest/gtest.h>
#include "src/gamelogic/gamemodel/CardRange.hpp"

TEST(card_range_test, select_policy) {
    GameModel::Board board{};

    GameModel::CardRange cardRange{board, 1};
    EXPECT_TRUE(cardRange.selectForPolicy(GameModel::CardType::Fascist));
    EXPECT_FALSE(cardRange.selectForPolicy(GameModel::CardType::Liberal));
}

TEST(card_range_test, constructor0) {
    GameModel::Board board{};

    GameModel::CardRange cardRange{board, 2};
    EXPECT_EQ(board.getCardPile().at(0), GameModel::CardType::Liberal);
    EXPECT_EQ(board.getCardPile().at(6), GameModel::CardType::Fascist);
    EXPECT_EQ(board.getCardPile().size(), 15);
}

TEST(card_range_test, destructor) {
    GameModel::Board board{};

    {
        GameModel::CardRange cardRange{board, 2};
        EXPECT_EQ(board.getCardPile().size(), 15);
    }

    EXPECT_EQ(board.getCardPile().size(), 17);
}

TEST(card_range_test, discard_card) {
    GameModel::Board board{};

    GameModel::CardRange cardRange{board, 2};
    EXPECT_TRUE(cardRange.discard(GameModel::CardType::Fascist));
    EXPECT_FALSE(cardRange.discard(GameModel::CardType::Liberal));
}

TEST(card_range_test, apply_to_game) {
    GameModel::Board board{};
    GameModel::CardRange cardRange{board, 3};

    EXPECT_TRUE(cardRange.discard(GameModel::CardType::Fascist));
    EXPECT_TRUE(cardRange.discard(GameModel::CardType::Fascist));
    EXPECT_TRUE(cardRange.selectForPolicy(GameModel::CardType::Fascist));
    EXPECT_EQ(board.getDiscardPile().size(), 0);
    EXPECT_TRUE(cardRange.applyToGame());

    EXPECT_EQ(board.getPolicyState().find(GameModel::CardType::Fascist)->second, 1);
    EXPECT_EQ(board.getPolicyState().find(GameModel::CardType::Liberal)->second, 0);
    EXPECT_EQ(board.getCardPile().size(), 14);
    EXPECT_EQ(board.getDiscardPile().size(), 2);
}