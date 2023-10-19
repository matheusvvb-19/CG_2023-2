/**
 * @file at02_mat4.h
 * @author Matheus Vargas Volpon Berto
 * @brief Implementação de operações matemáticas básicas entre matrizes de quatro dimensões
 * @version 0.1
 * @date 2023-10-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MAT4_H
#define MAT4_H

#include <stdexcept>

class mat4 {
   public:
    double m[4][4];

    /**
     * @brief Construtor da matriz sem valores pré-definidos pelo usuário
     *
     */
    mat4() {
        m[0][0] = 1.0;
        m[0][1] = 0.0;
        m[0][2] = 0.0;
        m[0][3] = 0.0;
        m[1][0] = 0.0;
        m[1][1] = 1.0;
        m[1][2] = 0.0;
        m[1][3] = 0.0;
        m[2][0] = 0.0;
        m[2][1] = 0.0;
        m[2][2] = 1.0;
        m[2][3] = 0.0;
        m[3][0] = 0.0;
        m[3][1] = 0.0;
        m[3][2] = 0.0;
        m[3][3] = 1.0;
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
     * @param j Décimo elemento da matriz
     * @param k Décimo primeiro elemento da matriz
     * @param l Décimo segundo elemento da matriz
     * @param n Décimo terceiro elemento da matriz
     * @param o Décimo quarto elemento da matriz
     * @param p Décimo quinto elemento da matriz
     * @param q Décimo sexto elemento da matriz
     */
    mat4(double a, double b, double c, double d, double e, double f, double g, double h, double i, double j, double k, double l, double n, double o, double p, double q) {
        m[0][0] = a;
        m[0][1] = b;
        m[0][2] = c;
        m[0][3] = d;
        m[1][0] = e;
        m[1][1] = f;
        m[1][2] = g;
        m[1][3] = h;
        m[2][0] = i;
        m[2][1] = j;
        m[2][2] = k;
        m[2][3] = l;
        m[3][0] = n;
        m[3][1] = o;
        m[3][2] = p;
        m[3][3] = q;
    }

    /**
     * @brief Multiplica uma matriz inicial por um escalar (t)
     *
     * @param t Escalar
     * @return mat4& Matriz resultante da multplicação entre a matriz inicial e o escalar t
     */
    mat4& operator*=(double t) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                m[i][j] *= t;
            }
        }
        return *this;
    }

    /**
     * @brief Divide uma matriz inicial por um escalar t
     *
     * @param t Escalar
     * @return mat4& Matriz resultante da divisão entre a matriz inicial e o escalar t
     */
    mat4& operator/=(double t) {
        if (t == 0.0) {
            throw std::runtime_error("Divisão por zero não permitida.");
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                m[i][j] /= t;
            }
        }
        return *this;
    }
};

/**
 * @brief Calcula a matriz transposta da matriz inicial
 *
 * @param A Matriz inicial
 * @return mat4 Matriz transposta
 */
inline mat4 const transpose(const mat4& A) {
    mat4 trans;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            trans.m[i][j] = A.m[j][i];
        }
    }
    return trans;
}

/**
 * @brief Calcula o determinante de uma matriz
 *
 * @param A Matriz inicial
 * @return double Determinante
 */
inline double const determinant(const mat4& A) {
    return A.m[0][0] * (A.m[1][1] * (A.m[2][2] * A.m[3][3] - A.m[3][2] * A.m[2][3]) - A.m[2][1] * (A.m[1][2] * A.m[3][3] - A.m[3][2] * A.m[1][3]) + A.m[3][1] * (A.m[1][2] * A.m[2][3] - A.m[2][2] * A.m[1][3])) -
           A.m[1][0] * (A.m[0][1] * (A.m[2][2] * A.m[3][3] - A.m[3][2] * A.m[2][3]) - A.m[2][1] * (A.m[0][2] * A.m[3][3] - A.m[3][2] * A.m[0][3]) + A.m[3][1] * (A.m[0][2] * A.m[2][3] - A.m[2][2] * A.m[0][3])) +
           A.m[2][0] * (A.m[0][1] * (A.m[1][2] * A.m[3][3] - A.m[3][2] * A.m[1][3]) - A.m[1][1] * (A.m[0][2] * A.m[3][3] - A.m[3][2] * A.m[0][3]) + A.m[3][1] * (A.m[0][2] * A.m[1][3] - A.m[1][2] * A.m[0][3])) -
           A.m[3][0] * (A.m[0][1] * (A.m[1][2] * A.m[2][3] - A.m[2][2] * A.m[1][3]) - A.m[1][1] * (A.m[0][2] * A.m[2][3] - A.m[2][2] * A.m[0][3]) + A.m[2][1] * (A.m[0][2] * A.m[1][3] - A.m[1][2] * A.m[0][3]));
}

/**
 * @brief Retorna a inversa de uma determinada matriz inicial
 *
 * @param A Matriz inicial
 * @return mat4 Matriz inversa
 */
inline mat4 const inverse(const mat4& A) {
    double det = determinant(A);
    if (det == 0.0) {
        throw std::runtime_error("A matriz não tem inversa (determinante zero).");
    }

    double invDet = 1.0 / det;
    mat4 inv;

    inv.m[0][0] = (A.m[1][1] * (A.m[2][2] * A.m[3][3] - A.m[3][2] * A.m[2][3]) - A.m[2][1] * (A.m[1][2] * A.m[3][3] - A.m[3][2] * A.m[1][3]) + A.m[3][1] * (A.m[1][2] * A.m[2][3] - A.m[2][2] * A.m[1][3])) * invDet;
    inv.m[0][1] = -(A.m[0][1] * (A.m[2][2] * A.m[3][3] - A.m[3][2] * A.m[2][3]) - A.m[2][1] * (A.m[0][2] * A.m[3][3] - A.m[3][2] * A.m[0][3]) + A.m[3][1] * (A.m[0][2] * A.m[2][3] - A.m[2][2] * A.m[0][3])) * invDet;
    inv.m[0][2] = (A.m[0][1] * (A.m[1][2] * A.m[3][3] - A.m[3][2] * A.m[1][3]) - A.m[1][1] * (A.m[0][2] * A.m[3][3] - A.m[3][2] * A.m[0][3]) + A.m[3][1] * (A.m[0][2] * A.m[1][3] - A.m[1][2] * A.m[0][3])) * invDet;
    inv.m[0][3] = -(A.m[0][1] * (A.m[1][2] * A.m[2][3] - A.m[2][2] * A.m[1][3]) - A.m[1][1] * (A.m[0][2] * A.m[2][3] - A.m[2][2] * A.m[0][3]) + A.m[2][1] * (A.m[0][2] * A.m[1][3] - A.m[1][2] * A.m[0][3])) * invDet;

    inv.m[1][0] = -(A.m[1][0] * (A.m[2][2] * A.m[3][3] - A.m[3][2] * A.m[2][3]) - A.m[2][0] * (A.m[1][2] * A.m[3][3] - A.m[3][2] * A.m[1][3]) + A.m[3][0] * (A.m[1][2] * A.m[2][3] - A.m[2][2] * A.m[1][3])) * invDet;
    inv.m[1][1] = (A.m[0][0] * (A.m[2][2] * A.m[3][3] - A.m[3][2] * A.m[2][3]) - A.m[2][0] * (A.m[0][2] * A.m[3][3] - A.m[3][2] * A.m[0][3]) + A.m[3][0] * (A.m[0][2] * A.m[2][3] - A.m[2][2] * A.m[0][3])) * invDet;
    inv.m[1][2] = -(A.m[0][0] * (A.m[1][2] * A.m[3][3] - A.m[3][2] * A.m[1][3]) - A.m[1][0] * (A.m[0][2] * A.m[3][3] - A.m[3][2] * A.m[0][3]) + A.m[3][0] * (A.m[0][2] * A.m[1][3] - A.m[1][2] * A.m[0][3])) * invDet;
    inv.m[1][3] = (A.m[0][0] * (A.m[1][2] * A.m[2][3] - A.m[2][2] * A.m[1][3]) - A.m[1][0] * (A.m[0][2] * A.m[2][3] - A.m[2][2] * A.m[0][3]) + A.m[2][0] * (A.m[0][2] * A.m[1][3] - A.m[1][2] * A.m[0][3])) * invDet;

    inv.m[2][0] = (A.m[1][0] * (A.m[2][1] * A.m[3][3] - A.m[3][1] * A.m[2][3]) - A.m[2][0] * (A.m[1][1] * A.m[3][3] - A.m[3][1] * A.m[1][3]) + A.m[3][0] * (A.m[1][1] * A.m[2][3] - A.m[2][1] * A.m[1][3])) * invDet;
    inv.m[2][1] = -(A.m[0][0] * (A.m[2][1] * A.m[3][3] - A.m[3][1] * A.m[2][3]) - A.m[2][0] * (A.m[0][1] * A.m[3][3] - A.m[3][1] * A.m[0][3]) + A.m[3][0] * (A.m[0][1] * A.m[2][3] - A.m[2][1] * A.m[0][3])) * invDet;
    inv.m[2][2] = (A.m[0][0] * (A.m[1][1] * A.m[3][3] - A.m[3][1] * A.m[1][3]) - A.m[1][0] * (A.m[0][1] * A.m[3][3] - A.m[3][1] * A.m[0][3]) + A.m[3][0] * (A.m[0][1] * A.m[1][3] - A.m[1][1] * A.m[0][3])) * invDet;
    inv.m[2][3] = -(A.m[0][0] * (A.m[1][1] * A.m[2][3] - A.m[2][1] * A.m[1][3]) - A.m[1][0] * (A.m[0][1] * A.m[2][3] - A.m[2][1] * A.m[0][3]) + A.m[2][0] * (A.m[0][1] * A.m[1][3] - A.m[1][1] * A.m[0][3])) * invDet;

    inv.m[3][0] = -(A.m[1][0] * (A.m[2][1] * A.m[3][2] - A.m[3][1] * A.m[2][2]) - A.m[2][0] * (A.m[1][1] * A.m[3][2] - A.m[3][1] * A.m[1][2]) + A.m[3][0] * (A.m[1][1] * A.m[2][2] - A.m[2][1] * A.m[1][2])) * invDet;
    inv.m[3][1] = (A.m[0][0] * (A.m[2][1] * A.m[3][2] - A.m[3][1] * A.m[2][2]) - A.m[2][0] * (A.m[0][1] * A.m[3][2] - A.m[3][1] * A.m[0][2]) + A.m[3][0] * (A.m[0][1] * A.m[2][2] - A.m[2][1] * A.m[0][2])) * invDet;
    inv.m[3][2] = -(A.m[0][0] * (A.m[1][1] * A.m[3][2] - A.m[3][1] * A.m[1][2]) - A.m[1][0] * (A.m[0][1] * A.m[3][2] - A.m[3][1] * A.m[0][2]) + A.m[3][0] * (A.m[0][1] * A.m[1][2] - A.m[1][1] * A.m[0][2])) * invDet;
    inv.m[3][3] = (A.m[0][0] * (A.m[1][1] * A.m[2][2] - A.m[2][1] * A.m[1][2]) - A.m[1][0] * (A.m[0][1] * A.m[2][2] - A.m[2][1] * A.m[0][2]) + A.m[2][0] * (A.m[0][1] * A.m[1][2] - A.m[1][1] * A.m[0][2])) * invDet;

    return inv;
}

/**
 * @brief Soma duas matrizes
 *
 * @param A Primeira matriz
 * @param B Segunda matriz
 * @return mat4 Matriz resultante da soma entre as matrizes A e B
 */
inline mat4 operator+(const mat4& A, const mat4& B) {
    mat4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
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
 * @return mat4 Matriz resultante da subtração entre as matrizes A e B
 */
inline mat4 operator-(const mat4& A, const mat4& B) {
    mat4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
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
 * @return mat4 Matriz resultante da multiplicação entre as matrizes A e B
 */
inline mat4 operator*(const mat4& A, const mat4& B) {
    mat4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.m[i][j] = 0.0;
            for (int k = 0; k < 4; k++) {
                result.m[i][j] += A.m[i][k] * B.m[k][j];
            }
        }
    }
    return result;
}

#endif
