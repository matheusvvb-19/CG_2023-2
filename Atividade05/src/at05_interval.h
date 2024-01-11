/**
 * @file at05_interval.h
 * @author Matheus Vargas Volpon Berto
 * @brief Arquivo de implementação da classe Interval
 * @version 0.1
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef INTERVAL_H
#define INTERVAL_H

class interval {
  public:
    double min, max;

    interval() : min(+infinity), max(-infinity) {} // Default interval is empty

    interval(double _min, double _max) : min(_min), max(_max) {}

    /**
     * @brief Retorna o tamanho do intervalo
     * 
     * @return double 
     */
    double size() const {
        return max - min;
    }

    /**
     * @brief Expansão do intervalo em ambas as direções
     * 
     * @param delta Valor de aumento
     * @return interval 
     */
    interval expand(double delta) const {
        auto padding = delta/2;
        return interval(min - padding, max + padding);
    }

    /**
     * @brief Verificação se o valor está presente no intervalo
     * 
     * @param x Valor a ser verificado
     * @return true 
     * @return false 
     */
    bool contains(double x) const {
        return min <= x && x <= max;
    }

    /**
     * @brief Verifica se o valor x está nos arredores do intervalo
     * 
     * @param x Valor a ser verificado
     * @return true 
     * @return false 
     */
    bool surrounds(double x) const {
        return min < x && x < max;
    }

    /**
     * @brief Verifica se um valor está fora do intervalo
     * 
     * @param x Valor a ser verificado
     * @return double 
     */
    double clamp(double x) const {
        if (x < min) return min;
        if (x > max) return max;
        return x;
    }

    static const interval empty, universe;
};

const interval interval::empty    = interval(+infinity, -infinity);
const interval interval::universe = interval(-infinity, +infinity);

#endif