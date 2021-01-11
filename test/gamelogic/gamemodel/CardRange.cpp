//
// Created by bjorn on 07.12.20.
//

#include <gtest/gtest.h>
#include "gamelogic/gamemodel/CardRange.hpp"

//TODO Test für mehr als 1 Karte wäheln und für falsche Karte
TEST(GameModel_CardRange, select_policy0) {
    GameModel::Board board{};

    GameModel::CardRange cardRange{board, 1};
    EXPECT_FALSE(cardRange.selectForPolicy(GameModel::CardType::LIBERAL));
    EXPECT_TRUE(cardRange.selectForPolicy(GameModel::CardType::FASCIST));
}

TEST(GameModel_CardRange, select_policy1) {
    GameModel::Board board{};

    GameModel::CardRange cardRange{board, 3};
    EXPECT_TRUE(cardRange.selectForPolicy(GameModel::CardType::FASCIST));
    EXPECT_FALSE(cardRange.selectForPolicy(GameModel::CardType::FASCIST));
}

TEST(GameModel_CardRange, constructor0) {
    GameModel::Board board{};

    GameModel::CardRange cardRange{board, 2};
    EXPECT_EQ(board.getCardPile().at(0), GameModel::CardType::LIBERAL);
    EXPECT_EQ(board.getCardPile().at(6), GameModel::CardType::FASCIST);
    EXPECT_EQ(board.getCardPile().size(), 15);
}

TEST(GameModel_CardRange, destructor) {
    GameModel::Board board{};

    {
        GameModel::CardRange cardRange{board, 2};
        EXPECT_EQ(board.getCardPile().size(), 15);
    }

    EXPECT_EQ(board.getCardPile().size(), 17);
}

TEST(GameModel_CardRange, discard_card) {
    GameModel::Board board{};

    GameModel::CardRange cardRange{board, 2};
    EXPECT_TRUE(cardRange.discard(GameModel::CardType::FASCIST));
    EXPECT_FALSE(cardRange.discard(GameModel::CardType::LIBERAL));
}

TEST(GameModel_CardRange, apply_to_game0) {
    GameModel::Board board{};
    GameModel::CardRange cardRange{board, 3};

    EXPECT_TRUE(cardRange.discard(GameModel::CardType::FASCIST));
    EXPECT_TRUE(cardRange.discard(GameModel::CardType::FASCIST));
    EXPECT_TRUE(cardRange.selectForPolicy(GameModel::CardType::FASCIST));
    EXPECT_EQ(board.getDiscardPile().size(), 0);
    EXPECT_TRUE(cardRange.applyToGame());

    EXPECT_EQ(board.getNumberOfPolicy(GameModel::CardType::FASCIST), 1);
    EXPECT_EQ(board.getNumberOfPolicy(GameModel::CardType::LIBERAL), 0);
    EXPECT_EQ(board.getCardPile().size(), 14);
    EXPECT_EQ(board.getDiscardPile().size(), 2);
}

TEST(GameModel_CardRange, apply_to_game1) {
    GameModel::Board board{};
    GameModel::CardRange cardRange{board, 3};

    EXPECT_TRUE(cardRange.discard(GameModel::CardType::FASCIST));
    EXPECT_TRUE(cardRange.selectForPolicy(GameModel::CardType::FASCIST));
    EXPECT_EQ(board.getDiscardPile().size(), 0);
    EXPECT_TRUE(cardRange.applyToGame());

    EXPECT_EQ(board.getNumberOfPolicy(GameModel::CardType::FASCIST), 1);
    EXPECT_EQ(board.getNumberOfPolicy(GameModel::CardType::LIBERAL), 0);
    EXPECT_EQ(board.getCardPile().size(), 15);
    EXPECT_EQ(board.getDiscardPile().size(), 1);
}

TEST(GameModel_CardRange, apply_to_game2) {
    GameModel::Board board{};
    GameModel::CardRange cardRange{board, 3};

    EXPECT_TRUE(cardRange.discard(GameModel::CardType::FASCIST));
    EXPECT_TRUE(cardRange.selectForPolicy(GameModel::CardType::FASCIST));
    EXPECT_EQ(board.getDiscardPile().size(), 0);
    EXPECT_TRUE(cardRange.discardRemainingCards());
    EXPECT_TRUE(cardRange.applyToGame());

    EXPECT_EQ(board.getNumberOfPolicy(GameModel::CardType::FASCIST), 1);
    EXPECT_EQ(board.getNumberOfPolicy(GameModel::CardType::LIBERAL), 0);
    EXPECT_EQ(board.getCardPile().size(), 14);
    EXPECT_EQ(board.getDiscardPile().size(), 2);
}