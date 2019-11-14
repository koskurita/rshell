CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
    unit_tests/DoubleAnd_test.hpp
unit_tests/DoubleSlash_test.hpp
unit_tests/ExecutableCommand_test.hpp
unit_tests/Line_Test.hpp
unit_tests/SemiColon.hpp
unit_tests/Symbol_test.hpp
unit_tests/UserInput_test.hpp

)

ADD_EXECUTABLE(rshell
    
    src/DoubleAnd.cpp
    src/DoubleSlash.cpp
    src/ExecutableCommand.cpp
    src/Line.cpp
    src/SemiColon.cpp
    src/Symbol.cpp
    src/UserInput.cpp
    header/DoubleAnd.hpp
    header/DoubleSlash.hpp
    header/ExecutableCommand.hpp
    header/Line.hpp
    header/SemiColon.hpp
    header/Symbol.hpp
    header/UserInput.hpp


)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)

