/**
 * @file at02_mat2.h
 * @author Matheus Vargas Volpon Berto
 * @brief Cabeçalhos e implementações de operações matemáticas básicas entre matrizes de duas dimensões
 * @version 0.1
 * @date 2023-10-17
 *
 * @copyright Copyright (c) 2023
 *
 */

// #include "at02_mat2.h"

#ifndef MAT2_H
#define MAT2_H

#include <stdexcept>

class mat2 {
   public:
    double m[2][2];

    /**
     * @brief Construtor da matriz sem valores pré-definidos pelo usuário
     *
     */
    mat2() {
        m[0][0] = 1.0;
        m[0][1] = 0.0;
        m[1][0] = 0.0;
        m[1][1] = 1.0;
    }

    /**
     * @brief Construtor da matriz com valores pré-definidos pelo usuário
     *
     * @param a Primeiro elemento da matriz
     * @param b Segundo elemento da matriz
     * @param c Terceiro elemento da matriz
     * @param d Quarto elemento da matriz
     */
    mat2(double a, double b, double c, double d) {
        m[0][0] = a;
        m[0][1] = b;
        m[1][0] = c;
        m[1][1] = d;
    }

    /**
     * @brief Multiplica uma matriz inicial por um escalar (t)
     *
     * @param t Escalar
     * @return mat2& Matriz resultante da multplicação entre a matriz inicial e o escalar t
     */
    mat2& operator*=(double t) {
        m[0][0] *= t;
        m[1][0] *= t;
        m[0][1] *= t;
        m[1][1] *= t;
        return *this;
    }

    /**
     * @brief Divide uma matriz inicial por um escalar t
     *
     * @param t Escalar
     * @return mat2& Matriz resultante da divisão entre a matriz inicial e o escalar t
     */
    mat2& operator/=(double t) {
        if (t == 0.0) {
            throw std::runtime_error("Divisão por zero não permitida.");
        }

        m[0][0] /= t;
        m[1][0] /= t;
        m[0][1] /= t;
        m[1][1] /= t;
        return *this;
    }
};

/**
 * @brief Calcula a matriz transposta da matriz inicial
 *
 * @param A Matriz inicial
 * @return mat2 Matriz transposta
 */
inline mat2 const transpose(const mat2& A) {
    mat2 trans;
    trans.m[0][0] = A.m[0][0];
    trans.m[1][0] = A.m[0][1];
    trans.m[0][1] = A.m[1][0];
    trans.m[1][1] = A.m[1][1];
    return trans;
}

/**
 * @brief Calcula o determinante de uma matriz
 *
 * @param A Matriz inicial
 * @return double Determinante
 */
inline double const determinant(const mat2& A) {
    return (A.m[0][0] * A.m[1][1] - A.m[1][0] * A.m[0][1]);
}

/**
 * @brief Retorna a inversa de uma determinada matriz inicial
 *
 * @param A Matriz inicial
 * @return mat2 Matriz inversa
 */
inline mat2 const inverse(const mat2& A) {
    double invdet = 1.0 / (A.m[0][0] * A.m[1][1] - A.m[1][0] * A.m[0][1]);
    mat2 inv;
    inv.m[0][0] = A.m[1][1] * invdet;
    inv.m[1][0] = -A.m[1][0] * invdet;
    inv.m[0][1] = -A.m[0][1] * invdet;
    inv.m[1][1] = A.m[0][0] * invdet;
    return inv;
}

/**
 * @brief Soma duas matrizes
 *
 * @param A Primeira matriz
 * @param B Segunda matriz
 * @return mat2 Matriz resultante da soma entre as matrizes A e B
 */
inline mat2 operator+(const mat2& A, const mat2& B) {
    mat2 result;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result.m[i][j] = A.m[i][j] + B.m[i][j];
        }
    }
    return result;
}

/**
 * @brief Subtrai duas matrizes
 *
 * @param A Primeira matriz
 * @param B Segunda matriz
 * @return mat2 Matriz resultante da subtração entre as matrizes A e B
 */
inline mat2 operator-(const mat2& A, const mat2& B) {
    mat2 result;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result.m[i][j] = A.m[i][j] - B.m[i][j];
        }
    }
    return result;
}

/**
 * @brief Multiplica duas matrizes
 *
 * @param A Primeira matriz
 * @param B Segunda matriz
 * @return mat2 Matriz resultante da multiplicação entre as matrizes A e B
 */
inline mat2 operator*(const mat2& A, const mat2& B) {
    mat2 result;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result.m[i][j] = 0.0;
            for (int k = 0; k < 2; k++) {
                result.m[i][j] += A.m[i][k] * B.m[k][j];
            }
        }
    }
    return result;
}

#endif
