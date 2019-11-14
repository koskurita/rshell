#include "everything.hpp"


TEST(SemiColonTest, TestSetPassOrFail) {
    UserInput * tester = new Symbol(";");
    tester->SetPassOrFail(1);
    EXPECT_EQ(tester->returnPassOrFail(), 0);
}
TEST(SemiColonTest, CorrectID) {
    UserInput * tester = new Symbol(";");
    EXPECT_EQ(tester->returnID(), 101);
}
TEST(SemiColonTest, ){
UserInput * tester = new SemiColon(";");
UserInput * fakeClassOne = new SemiColon(";");
UserInput * fakeClassTwo = new SemiColon(";");
EXPECT_EQ(tester->PerformNext(fakeClassOne,fakeClassTwo), true);
}

