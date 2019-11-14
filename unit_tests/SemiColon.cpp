#include "everything.hpp"
#include "gtest/gtest.h"

TEST(SemiColonTest, TestSetPassOrFail) {
    const char* p = ';';
    UserInput * tester = new SemiColon(p);
    tester->SetPassOrFail(1);
    EXPECT_EQ(tester->returnPassOrFail(), 0);
}


