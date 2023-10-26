cmake_minimum_required(VERSION 3.8)

project(Atividade03 CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Headers
    src/at03_myClass_objLoader.hpp
)

add_library(Atividade03Lib ${Headers})
set_target_properties(Atividade03Lib PROPERTIES LINKER_LANGUAGE CXX)  # Define a linguagem do linker

add_subdirectory(tests)