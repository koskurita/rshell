CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
    ../assignment-team_robert_kosuke/unit_tests/DoubleAnd_test.hpp
../assignment-team_robert_kosuke/unit_tests/DoubleSlash_test.hpp
../assignment-team_robert_kosuke/unit_tests/ExecutableCommand_test.hpp
../assignment-team_robert_kosuke/unit_tests/Line_Test.hpp
../assignment-team_robert_kosuke/unit_tests/SemiColon.hpp
../assignment-team_robert_kosuke/unit_tests/Symbol_test.hpp
../assignment-team_robert_kosuke/unit_tests/UserInput_test.hpp

)

ADD_EXECUTABLE(rshell
    ../assignment-team_robert_kosuke/src/main.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)

