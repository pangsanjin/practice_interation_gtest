//
// Created by yanciliu on 2019/8/19.
//

#include "../deps/googletest/googletest/include/gtest/gtest.h"

int add(int a, int b){
    return a+b;
}

TEST(test1, c1){
EXPECT_EQ(3, add(1,2));
}