#include "everything.hpp"
#include "gtest/gtest.h"

TEST(UserInputTest, TestSetPassOrFail) {
    const char* arr[50];
    UserInput * tester = new ExecutableCommand(arr);
    tester->SetPassOrFail(1);
    EXPECT_EQ(tester->returnPassOrFail(), 1);

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
