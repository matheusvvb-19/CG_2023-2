#include <gtest/gtest.h>

#include <typeinfo>

#include "../src/at02_mat2.hpp"
#include "../src/at02_mat3.hpp"
#include "../src/at02_mat4.hpp"
#include "../src/at02_vec2.hpp"
#include "../src/at02_vec4.hpp"

TEST(at02_tests, TestingVEC2) {
    // ###################### CLASSE VEC2 ######################
    vec2 v;
    vec2 u(2, 7.5);

    // inicialização do vetor:
    EXPECT_EQ(v.x(), 1.0);
    EXPECT_EQ(v.y(), 0.0);

    EXPECT_EQ(u.x(), 2.0);
    EXPECT_EQ(u.y(), 7.5);

    // vetor oposto:
    EXPECT_EQ(u.operator-().x(), -2.0);
    EXPECT_EQ(u.operator-().y(), -7.5);

    // elemento em índice específico:
    ASSERT_THROW(v.operator[](3), std::runtime_error);
    ASSERT_THROW(v.operator[](-2) = 5.2, std::runtime_error);

    // operador +=:
    vec2 w(3, 4);
    vec2 vetor_resultante = v.operator+=(w);
    EXPECT_EQ(vetor_resultante.x(), 4.0);
    EXPECT_EQ(vetor_resultante.y(), 4.0);

    // operador *=:
    vetor_resultante = u.operator*=(-3);
    EXPECT_EQ(vetor_resultante.x(), -6.0);
    EXPECT_EQ(vetor_resultante.y(), -22.5);

    // operador /=:
    vetor_resultante = w.operator/=(0.5);
    ASSERT_THROW(u.operator/=(0), std::runtime_error);
    EXPECT_EQ(vetor_resultante.x(), 6);
    EXPECT_EQ(vetor_resultante.y(), 8);

    // ###################### CLASSE VEC4 ######################
    vec4 v_4;
    vec4 u_4(2, 2, 2, 2);

    // inicialização do vetor:
    EXPECT_EQ(v_4.x(), 1.0);
    EXPECT_EQ(v_4.y(), 0.0);
    EXPECT_EQ(v_4.z(), 0.0);
    EXPECT_EQ(v_4.w(), 0.0);

    // length:
    ASSERT_TRUE(u_4.length() == 4);

    // length_squared:
    EXPECT_EQ(u_4.length_squared(), 16);

    // operador +:
    ASSERT_TRUE(typeid(operator+(v_4, u_4)) == typeid(vec4));
    EXPECT_EQ(operator+(v_4, u_4).x(), 3);
    EXPECT_EQ(operator+(v_4, u_4).y(), 2);
    EXPECT_EQ(operator+(v_4, u_4).z(), 2);
    EXPECT_EQ(operator+(v_4, u_4).w(), 2);

    // operador *:
    ASSERT_TRUE(typeid(operator*(v_4, u_4)) == typeid(vec4));
    EXPECT_EQ(operator*(v_4, u_4).x(), 2);
    EXPECT_EQ(operator*(v_4, u_4).y(), 0);
    EXPECT_EQ(operator*(v_4, u_4).z(), 0);
    EXPECT_EQ(operator*(v_4, u_4).w(), 0);

    ASSERT_TRUE(typeid(operator*(u_4, 3)) == typeid(vec4));
    EXPECT_EQ(operator*(u_4, 3).x(), 6);
    EXPECT_EQ(operator*(u_4, 3).y(), 6);
    EXPECT_EQ(operator*(u_4, 3).z(), 6);
    EXPECT_EQ(operator*(u_4, 3).w(), 6);

    ASSERT_TRUE(typeid(operator*(3, u_4)) == typeid(vec4));
    EXPECT_EQ(operator*(3, u_4).x(), 6);
    EXPECT_EQ(operator*(3, u_4).y(), 6);
    EXPECT_EQ(operator*(3, u_4).z(), 6);
    EXPECT_EQ(operator*(3, u_4).w(), 6);

    // operador /:
    ASSERT_THROW(operator/(u_4, 0), std::runtime_error);
    EXPECT_EQ(operator/(u_4, 2).x(), 1);
    EXPECT_EQ(operator/(u_4, 2).y(), 1);
    EXPECT_EQ(operator/(u_4, 2).z(), 1);
    EXPECT_EQ(operator/(u_4, 2).w(), 1);

    // vetor unitário:
    ASSERT_TRUE(typeid(unit_vector(u_4)) == typeid(vec4));
    EXPECT_EQ(unit_vector(u_4).x(), 0.5);
    EXPECT_EQ(unit_vector(u_4).y(), 0.5);
    EXPECT_EQ(unit_vector(u_4).z(), 0.5);
    EXPECT_EQ(unit_vector(u_4).w(), 0.5);

    // ###################### CLASSE MAT2 ######################
    mat2 a_2;
    mat2 b_2(3, 7, 1, 4);

    // inicialização da matriz:
    EXPECT_EQ(a_2.m[0][0], 1);
    EXPECT_EQ(a_2.m[0][1], 0);
    EXPECT_EQ(a_2.m[1][0], 0);
    EXPECT_EQ(a_2.m[1][1], 1);

    EXPECT_EQ(b_2.m[0][0], 3);
    EXPECT_EQ(b_2.m[0][1], 7);
    EXPECT_EQ(b_2.m[1][0], 1);
    EXPECT_EQ(b_2.m[1][1], 4);

    // operador *=:
    mat2 matriz_resultante = b_2.operator*=(1.5);
    ASSERT_TRUE(typeid(matriz_resultante) == typeid(mat2));
    EXPECT_EQ(matriz_resultante.m[0][0], 4.5);
    EXPECT_EQ(matriz_resultante.m[0][1], 10.5);
    EXPECT_EQ(matriz_resultante.m[1][0], 1.5);
    EXPECT_EQ(matriz_resultante.m[1][1], 6);

    // operador /=:
    matriz_resultante = a_2.operator/=(2);
    ASSERT_TRUE(typeid(matriz_resultante) == typeid(mat2));
    EXPECT_EQ(matriz_resultante.m[0][0], 0.5);
    EXPECT_EQ(matriz_resultante.m[0][1], 0);
    EXPECT_EQ(matriz_resultante.m[1][0], 0);
    EXPECT_EQ(matriz_resultante.m[1][1], 0.5);

    // operador *:
    mat2 c_2(1, 8, 3.2, 9);
    mat2 d_2;
    matriz_resultante = operator*(c_2, d_2);
    EXPECT_EQ(matriz_resultante.m[0][0], 1);
    EXPECT_EQ(matriz_resultante.m[0][1], 8);
    EXPECT_EQ(matriz_resultante.m[1][0], 3.2);
    EXPECT_EQ(matriz_resultante.m[1][1], 9);
}
