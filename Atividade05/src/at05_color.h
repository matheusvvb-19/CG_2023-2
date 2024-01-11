/**
 * @file at05_color.h
 * @author Matheus Vargas Volpon Berto
 * @brief Arquivo de implementadação da classe Color
 * @version 0.1
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef COLOR_H
#define COLOR_H

#include "../../Atividade02/src/at02_vec3.hpp"
#include <iostream>

using color = vec3;

/**
 * @brief Transformação para espaço gamma
 * 
 * @param linear_component Componente de correção
 * @return double 
 */
inline double linear_to_gamma(double linear_component)
{
    return sqrt(linear_component);
}

/**
 * @brief Escrita de cor em um pixel
 * 
 * @param out Saída do ppm
 * @param pixel_color Vetor de cor
 * @param samples_per_pixel Amostras por pixel da imagem
 */
void write_color(std::ostream &out, color pixel_color, int samples_per_pixel) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    auto scale = 1.0 / samples_per_pixel;
    r *= scale;
    g *= scale;
    b *= scale;

    r = linear_to_gamma(r);
    g = linear_to_gamma(g);
    b = linear_to_gamma(b);

    static const interval intensity(0.000, 0.999);
    out << static_cast<int>(256 * intensity.clamp(r)) << ' '
        << static_cast<int>(256 * intensity.clamp(g)) << ' '
        << static_cast<int>(256 * intensity.clamp(b)) << '\n';
}


#endif