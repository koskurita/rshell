#include "everything.hpp"
#include "gtest/gtest.h"




TEST(LineTest, TestSetPassOrFail) {//LineTest
    UserInput * tester = new Line();
    tester->SetPassOrFail(1);//1
    EXPECT_EQ(tester->returnPassOrFail(), 1);


}

TEST(DoubleAndTest, TestSetPassOrFail) {//DoubleAndTest
    const char* p = "p";
    UserInput * tester = new DoubleAnd(p);
    tester->SetPassOrFail(1);//2
    EXPECT_EQ(tester->returnPassOrFail(), 1);
}

TEST(DoubleAndTest, TestID) {//DoubleAndTest
    
    const char* p = "p";
    UserInput * tester = new DoubleAnd(p);
    EXPECT_EQ(tester->ReadID, 103);
}

TEST(DoubleSlashTest, TestSetPassOrFail){//SlashTest
    const char * p = "p";
    UserInput * tester = new DoubleSlash(p);
    tester->SetPassOrFail(1);//3
    EXPECT_EQ(tester->returnPassOrFail(), 1);
}

TEST(DoubleAndTest, TestPerformNextFirstExeFail) {//DOubleAndTest
    const char* arr[50];
    const char* one = "ls";
    const char* two = NULL;
    arr[0] = one;
    arr[1] = two;
    UserInput * Ex1 = new ExecutableCommand(arr);
    UserInput * Ex2 = new ExecutableCommand(arr);
    UserInput * mySymbol = new DoubleAnd(one);
    Ex1->SetPassOrFail(0);
    mySymbol->PerformNext(Ex1,Ex2);//this gives Ex2 0
    EXPECT_EQ(Ex2->returnPassOrFail(), 0);
}

TEST(DoubleAndTest, TestPerformNextFirstExePass) {//DOubleAndTest
    const char* arr[50];
    const char* one = "ls";
    const char* two = NULL;
    arr[0] = one;
    arr[1] = two;
    UserInput * Ex1 = new ExecutableCommand(arr);
    UserInput * Ex2 = new ExecutableCommand(arr);
    UserInput * mySymbol = new DoubleAnd(one);
    Ex1->SetPassOrFail(1);
    mySymbol->PerformNext(Ex1,Ex2);//ex2 gives -1
    EXPECT_EQ(Ex2->returnPassOrFail(), -1);
}

TEST(DoubleSlash, TestPerformNextFirstExeFail) {//DOubleAndTest
    const char* arr[50];
    const char* one = "ls";
    const char* two = NULL;
    arr[0] = one;
    arr[1] = two;
    UserInput * Ex1 = new ExecutableCommand(arr);
    UserInput * Ex2 = new ExecutableCommand(arr);
    UserInput * mySymbol = new DoubleSlash(one);
    Ex1->SetPassOrFail(0);
    mySymbol->PerformNext(Ex1,Ex2);//ex2 returns negative one 
    EXPECT_EQ(Ex2->returnPassOrFail(), -1);
}



TEST(DoubleSlash, TestPerformNextFirstExePass) {//DOubleAndTest
    const char* arr[50];
    const char* one = "ls";
    const char* two = NULL;
    arr[0] = one;
    arr[1] = two;
    UserInput * Ex1 = new ExecutableCommand(arr);
    UserInput * Ex2 = new ExecutableCommand(arr);
    UserInput * mySymbol = new DoubleSlash(one);
    Ex1->SetPassOrFail(1);
    mySymbol->PerformNext(Ex1,Ex2);
    EXPECT_EQ(Ex2->returnPassOrFail(), 0);
}



TEST(ExecutableCommandTest, TestSetPassOrFail) {
    const char* arr[50];
    const char* one = "ls";
    const char* two = NULL;
    arr[0] = one;
    arr[1] = two;
    UserInput * tester = new ExecutableCommand(arr);
    tester->SetPassOrFail(1);//4
    EXPECT_EQ(tester->returnPassOrFail(), 1);
}

TEST(SemiColonTest, TestSetPassOrFail) {
   const char * p = ";";
   UserInput * tester = new SemiColon(p);
    tester->SetPassOrFail(1);//5
    EXPECT_EQ(tester->returnPassOrFail(), 1);
}

TEST(SymbolTest, TestSetPassOrFail) {
    const char* p = "&&";
    UserInput * tester = new Symbol(p);
    tester->SetPassOrFail(1);//6
    EXPECT_EQ(tester->returnPassOrFail(), 1);
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
