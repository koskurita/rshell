
#include "everything.hpp"


TEST(UserInputTest, TestSetPassOrFail) {
    UserInput * tester = new DoubleAnd();
    tester->SetPassOrFail(1);
    EXPECT_EQ(tester->returnPassOrFail(), 1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
    
