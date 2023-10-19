/**
 * @file at02_mat3.h
 * @author Matheus Vargas Volpon Berto
 * @brief Implementação de operações matemáticas básicas entre matrizes de três dimensões
 * @version 0.1
 * @date 2023-10-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MAT3_H
#define MAT3_H

#include <stdexcept>

class mat3 {
   public:
    double m[3][3];

    /**
     * @brief Construtor da matriz sem valores pré-definidos pelo usuário
     *
     */
    mat3() {
        m[0][0] = 1.0;
        m[0][1] = 0.0;
        m[0][2] = 0.0;
        m[1][0] = 0.0;
        m[1][1] = 1.0;
        m[1][2] = 0.0;
        m[2][0] = 0.0;
        m[2][1] = 0.0;
        m[2][2] = 1.0;
    }

    /**
     * @brief Construtor da matriz com valores pré-definidos pelo usuário
     *
     * @param a Primeiro elemento da matriz
     * @param b Segundo elemento da matriz
     * @param c Terceiro elemento da matriz
     * @param d Quarto elemento da matriz
     * @param e Quinto elemento da matriz
     * @param f Sexto elemento da matriz
     * @param g Sétimo elemento da matriz
     * @param h Oitavo elemento da matriz
     * @param i Nono elemento da matriz
     */
    mat3(double a, double b, double c, double d, double e, double f, double g, double h, double i) {
        m[0][0] = a;
        m[0][1] = b;
        m[0][2] = c;
        m[1][0] = d;
        m[1][1] = e;
        m[1][2] = f;
        m[2][0] = g;
        m[2][1] = h;
        m[2][2] = i;
    }

    /**
     * @brief Multiplica uma matriz inicial por um escalar (t)
     *
     * @param t Escalar
     * @return mat3& Matriz resultante da multplicação entre a matriz inicial e o escalar t
     */
    mat3& operator*=(double t) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                m[i][j] *= t;
            }
        }
        return *this;
    }

    /**
     * @brief Divide uma matriz inicial por um escalar t
     *
     * @param t Escalar
     * @return mat3& Matriz resultante da divisão entre a matriz inicial e o escalar t
     */
    mat3& operator/=(double t) {
        if (t == 0.0) {
            throw std::runtime_error("Divisão por zero não permitida.");
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                m[i][j] /= t;
            }
        }
        return *this;
    }
};

/**
 * @brief Soma duas matrizes
 *
 * @param A Primeira matriz
 * @param B Segunda matriz
 * @return mat3 Matriz resultante da soma entre as matrizes A e B
 */
inline mat3 operator+(const mat3& A, const mat3& B) {
    mat3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
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
 * @return mat3 Matriz resultante da subtração entre as matrizes A e B
 */
inline mat3 operator-(const mat3& A, const mat3& B) {
    mat3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
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
 * @return mat3 Matriz resultante da multiplicação entre as matrizes A e B
 */
inline mat3 operator*(const mat3& A, const mat3& B) {
    mat3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.m[i][j] = 0.0;
            for (int k = 0; k < 3; k++) {
                result.m[i][j] += A.m[i][k] * B.m[k][j];
            }
        }
    }
    return result;
}

#endif
