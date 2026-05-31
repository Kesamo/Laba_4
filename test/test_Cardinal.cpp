#include <gtest/gtest.h>
#include "Cardinal.hpp"

TEST(Cardinal, get_value){
    Cardinal c(42);
    EXPECT_EQ(c.get_value(), 42);
}

TEST(Cardinal, is_finite){
    Cardinal c(10);
    EXPECT_TRUE(c.is_finite());
    EXPECT_FALSE(c.is_infinite());
}


TEST(Cardinal, is_infinite){
    Cardinal c = Cardinal::inf();
    EXPECT_TRUE(c.is_infinite());
    EXPECT_FALSE(c.is_finite());
}

TEST(Cardinal, get_value_Exceptions){
    Cardinal c = Cardinal::inf();
    EXPECT_THROW(c.get_value(), InfiniteException);
}

TEST(Cardinal, get_value_Zero){
    Cardinal c(0);
    EXPECT_TRUE(c.is_finite());
    EXPECT_EQ(c.get_value(), 0);
}