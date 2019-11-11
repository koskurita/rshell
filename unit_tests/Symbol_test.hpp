#include "UserInput.cpp"
#include "Symbol.cpp"
#include "gtest/gtest.h"


TEST(SymbolTest, TestSetPassOrFail) {
    UserInput * tester = new Symbol("&&");
    tester->SetPassOrFail(1);
    EXPECT_EQ(tester->returnPassOrFail(), 0);
}
TEST(SymbolTest, CorrectID) {
    UserInput * tester = new Symbol();
    EXPECT_EQ(tester->returnID(), 100);
}



