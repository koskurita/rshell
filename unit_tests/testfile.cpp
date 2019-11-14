#include "everything.hpp"
#include "gtest/gtest.h"

TEST(LineTest, TestSetPassOrFail) {
    UserInput * tester = new Line();
    tester->SetPassOrFail(1);
    EXPECT_EQ(tester->returnPassOrFail(), 1);


}

TEST(DoubleAndTest, TestSetPassOrFail) {
    const char* p = "p";
    UserInput * tester = new DoubleAnd(p);
    tester->SetPassOrFail(1);
    EXPECT_EQ(tester->returnPassOrFail(), -1);
}

TEST(DoubleSlashTest, TestSetPassOrFail) {
    const char* p = "p";
    UserInput * tester = new DoubleSlash(p);
    tester->SetPassOrFail(1);
    EXPECT_EQ(tester->returnPassOrFail(), -1);
}

TEST(ExecutableCommandTest, TestSetPassOrFail) {
    const char* arr[50];
    UserInput * tester = new ExecutableCommand(arr);
    tester->SetPassOrFail(1);
    EXPECT_EQ(tester->returnPassOrFail(), 1);
}

TEST(SemiColonTest, TestSetPassOrFail) {
    const char* p = "";"";
    UserInput * tester = new SemiColon(p);
    tester->SetPassOrFail(1);
    EXPECT_EQ(tester->returnPassOrFail(), -1);
}

TEST(SymbolTest, TestSetPassOrFail) {
    const char* p = "&&";
    UserInput * tester = new Symbol(p);
    tester->SetPassOrFail(1);
    EXPECT_EQ(tester->returnPassOrFail(), -1);
}

TEST(UserInputTest, TestSetPassOrFail) {
    UserInput * tester = new Line();
    tester->SetPassOrFail(1);
    EXPECT_EQ(tester->returnPassOrFail(), 1);

}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
