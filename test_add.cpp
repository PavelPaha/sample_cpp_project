#include <gtest/gtest.h>

#include "my_add.hpp"

TEST(Add_Simple_Test, Simple) {
    EXPECT_EQ(add(2, 2), 4);
    EXPECT_EQ(add(2, 3), add(3, 2));
    EXPECT_EQ(add(-42, 3), -39);
}