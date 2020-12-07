#include <gtest/gtest.h>

#include <messages/Error.hpp>

using namespace messages;

TEST(Messages_Error, Serialization) {
    Error error;
    error.message = "test";

    EXPECT_EQ(error, *Message::fromJson(error.toJson()));
}
