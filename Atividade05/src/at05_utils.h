/**
 * @file at05_utils.h
 * @author Matheus Vargas Volpon Berto
 * @brief Arquivo de implementação da classe Utils
 * @version 0.1
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef UTILS_H
#define UTILS_H

#include <cmath>
#include <limits>
#include <memory>
#include <random>

// Usings
using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

/**
 * @brief Conversão de graus para radianos
 * 
 * @param degrees Graus a serem convertidos
 * @return double 
 */
inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

/**
 * @brief Obtenção de número float aleatório
 * 
 * @return double 
 */
inline double random_double() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

/**
 * @brief Obtenção de número float aleatório dentro de intervalo
 * 
 * @param min 
 * @param max 
 * @return double 
 */
inline double random_double(double min, double max) {
    static std::uniform_real_distribution<double> distribution(min, max);
    static std::mt19937 generator;
    return distribution(generator);
}

// Common headers
#include "./at05_interval.h"
#include "../../Atividade04/src/at04_ray.h"
#include "../../Atividade02/src/at02_vec3.hpp"

#endif