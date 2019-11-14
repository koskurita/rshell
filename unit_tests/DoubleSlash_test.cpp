#include "everything.cpp"
#include "gtest/gtest.h"

TEST(UserInputTest, TestSetPassOrFail) {
    const char* p = 'p';
    UserInput * tester = new DoubleSlash(p);
    tester->SetPassOrFail(1);
    EXPECT_EQ(tester->returnPassOrFail(), 1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
