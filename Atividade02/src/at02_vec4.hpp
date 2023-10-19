/**
 * @file at02_vec4.h
 * @author Matheus Vargas Volpon Berto
 * @brief Implementação de operações matemáticas básicas entre vetores de quatro dimensões
 * @version 0.1
 * @date 2023-10-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef VEC4_H
#define VEC4_H

#include <cmath>
#include <iostream>
#include <stdexcept>

using std::sqrt;

class vec4 {
   public:
    double e[4];

    /**
     * @brief Construtor do vetor sem valores pré-definidos pelo usuário
     *
     */
    vec4() : e{1, 0, 0, 0} {}

    /**
     * @brief Construtor do vetor com valores pré-definidos pelo usuário
     *
     * @param e0 Primeiro elemento do vetor
     * @param e1 Segundo elemento do vetor
     * @param e2 Terceiro elemento do vetor
     * @param e3 Quarto elemento do vetor
     */
    vec4(double e0, double e1, double e2, double e3) : e{e0, e1, e2, e3} {}

    /**
     * @brief Acessa o primeiro elemento (coordenada x) do vetor
     *
     * @return double Coordenada x
     */
    double x() const { return e[0]; }

    /**
     * @brief Acessa o segundo elemento (coordenada y) do vetor
     *
     * @return double Coordenada y
     */
    double y() const { return e[1]; }

    /**
     * @brief Acessa o terceiro elemento (coordenada z) do vetor
     *
     * @return double Coordenada z
     */
    double z() const { return e[2]; }

    /**
     * @brief Acessa o quarto elemento (coordenada w) do vetor
     *
     * @return double Coordenada w
     */
    double w() const { return e[3]; }

    /**
     * @brief Retorna o vetor oposto
     *
     * @return vec4 Vetor oposto
     */
    vec4 operator-() const { return vec4(-e[0], -e[1], -e[2], -e[3]); }

    /**
     * @brief Acessa um elemento específico do vetor, sem alterá-lo
     *
     * @param i Índice desejado
     * @return double Elemento do vetor no índice desejado
     */
    double operator[](int i) const {
        if (i <= -1 || i >= 4) {
            throw std::runtime_error("Índice " + std::to_string(i) + " inexistente em um vetor de duas dimensões.");
        }

        return e[i];
    }

    /**
     * @brief Acessa um elemento específico do vetor, podendo alterá-lo
     *
     * @param i Índice desejado
     * @return double& Referência para o elemento do vetor no índice desejado
     */
    double& operator[](int i) {
        if (i <= -1 || i >= 4) {
            throw std::runtime_error("Índice " + std::to_string(i) + " inexistente em um vetor de duas dimensões.");
        }

        return e[i];
    }

    /**
     * @brief Soma um segundo vetor (v) ao vetor inicial
     *
     * @param v Vetor a ser adicionado
     * @return vec4& Vetor resultante da soma entre o vetor inicial e o vetor v
     */
    vec4& operator+=(const vec4& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        e[3] += v.e[3];
        return *this;
    }

    /**
     * @brief Multiplica um vetor inicial por um escalar (t)
     *
     * @param t Escalar
     * @return vec2& Vetor resultante da multplicação entre o vetor inicial e o escalar t
     */
    vec4& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        e[3] *= t;
        return *this;
    }

    /**
     * @brief Divide um vetor inicial por um escalar t
     *
     * @param t Escalar
     * @return vec2& Vetor resultante da divisão entre o vetor inicial e o escalar t
     */
    vec4& operator/=(double t) {
        if (t == 0.0) {
            throw std::runtime_error("Divisão por zero não permitida.");
        }

        return *this *= 1 / t;
    }

    /**
     * @brief Calcula a raiz quadrada da soma dos quadrados das coordenadas (x, y) do vetor
     *
     * @return double Raiz quadrada da soma dos quadrados das coordenadas
     */
    double length() const {
        return sqrt(length_squared());
    }

    /**
     * @brief Calcula a soma dos quadrados das coordenadas (x, y) do vetor
     *
     * @return double Soma dos quadrados das coordenadas
     */
    double length_squared() const {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2] + e[3] * e[3];
    }
};

/**
 * @brief Imprime na tela as coordenadas do vetor
 *
 * @param out Variável de saída para impressão
 * @param v Vetor a ser impresso
 * @return std::ostream& Impressão na tela das coordenadas do vetor
 */
inline std::ostream& operator<<(std::ostream& out, const vec4& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2] << ' ' << v.e[3];
}

/**
 * @brief Realiza a soma entre dois vetores
 *
 * @param u Primeiro vetor
 * @param v Segundo vetor
 * @return vec2 Vetor resultante
 */
inline vec4 operator+(const vec4& u, const vec4& v) {
    return vec4(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2], u.e[3] + v.e[3]);
}

/**
 * @brief Realiza a subtração entre dois vetores
 *
 * @param u Primeiro vetor
 * @param v Segundo vetor
 * @return vec2 Vetor resultante
 */
inline vec4 operator-(const vec4& u, const vec4& v) {
    return vec4(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2], u.e[3] - v.e[3]);
}

/**
 * @brief Realiza a multiplicação entre dois vetores
 *
 * @param u Primeiro vetor
 * @param v Segundo vetor
 * @return vec2 Vetor resultante
 */
inline vec4 operator*(const vec4& u, const vec4& v) {
    return vec4(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2], u.e[3] * v.e[3]);
}

/**
 * @brief Realiza a multiplicação entre um escalar e um vetor
 *
 * @param t Escalar
 * @param v Vetor
 * @return vec2 Vetor resultante
 */
inline vec4 operator*(double t, const vec4& v) {
    return vec4(t * v.e[0], t * v.e[1], t * v.e[2], t * v.e[3]);
}

/**
 * @brief Realiza a multiplicação entre um vetor e um escalar
 *
 * @param v Vetor
 * @param t Escalar
 * @return vec2 Vetor resultante
 */
inline vec4 operator*(const vec4& v, double t) {
    return t * v;
}

/**
 * @brief Realiza a divisão entre um vetor e um escalar
 *
 * @param v Vetor
 * @param t Escalar
 * @return vec2 Vetor resultante
 */
inline vec4 operator/(vec4 v, double t) {
    if (t == 0.0) {
        throw std::runtime_error("Divisão por zero não permitida.");
    }

    return (1 / t) * v;
}

/**
 * @brief Realiza o cálculo de produto escalar entre dois vetores
 *
 * @param u Primeiro vetor
 * @param v Segundo vetor
 * @return double Produto escalar entre os dois vetores
 */
inline double dot(const vec4& u, const vec4& v) {
    return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2] + u.e[3] * v.e[3];
}

/**
 * @brief Cacula o vetor unitário de um determinado vetor inicial
 *
 * @param v Vetor inicial
 * @return vec2 Vetor unitário resultante
 */
inline vec4 unit_vector(vec4 v) {
    return v / v.length();
}

#endif
