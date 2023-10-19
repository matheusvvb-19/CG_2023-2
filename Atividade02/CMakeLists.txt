cmake_minimum_required(VERSION 3.8)

project(Atividade02 CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Headers
    src/at02_vec2.hpp
    src/at02_vec4.hpp
    src/at02_mat2.hpp
    src/at02_mat3.hpp
    src/at02_mat4.hpp
)

add_library(Atividade02Lib ${Headers})
set_target_properties(Atividade02Lib PROPERTIES LINKER_LANGUAGE CXX)  # Define a linguagem do linker

add_subdirectory(tests)
