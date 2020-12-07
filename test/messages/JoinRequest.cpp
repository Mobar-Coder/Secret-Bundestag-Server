#include <gtest/gtest.h>

#include <messages/JoinRequest.hpp>

using namespace messages;

TEST(Messages_JoinRequest, Serialization) {
    JoinRequest joinRequest;
    joinRequest.lobbyName = "abc";

    EXPECT_EQ(joinRequest, *Message::fromJson(joinRequest.toJson()));
}
