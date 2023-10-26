cmake_minimum_required(VERSION 3.8)

set(This MyTest)

set(Sources at03_tests.cpp)

add_executable(${This} ${Sources})
target_link_libraries(${This} gtest gtest_main Atividade03Lib)

add_test(
    Name ${This}
    COMMAND ${This}
)