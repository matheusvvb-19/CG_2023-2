/**
 * @file at05_vertex.h
 * @author Matheus Vargas Volpon Berto
 * @brief Arquivo de implementação da classe Vertex
 * @version 0.1
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef VERTEX_H
#define VERTEX_H

#include "../../Atividade02/src/at02_vec3.hpp"

class vertex {
    public:
        point3 coord;
        vec3 normal;

        vertex(const point3& _coord, const point3& _normal): 
            coord(_coord), normal(_normal) {}
};

#endif