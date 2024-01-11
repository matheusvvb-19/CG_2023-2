/**
 * @file at05_hittable.h
 * @author Matheus Vargas Volpon Berto
 * @brief Arquivo de implementação das classes Hit_record e Hittable
 * @version 0.1
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef HITTABLE_H
#define HITTABLE_H

#include "./at05_utils.h"

class material;

class hit_record {
  public:
    point3 p;
    vec3 normal;
    shared_ptr<material> mat;
    double t;
    bool front_face;

    /**
     * @brief Definição da normal da face
     * 
     * @param r Raio
     * @param outward_normal Normal inversa
     */
    void set_face_normal(const ray& r, const vec3& outward_normal) {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }

    /**
     * @brief Definição da normal da face
     * 
     * @param r Raio
     * @param outward_normal Normal inversa
     * @param color_normal Cor da normal
     */
    void set_face_normal(const ray& r, const vec3& outward_normal, const vec3&color_normal) {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? color_normal : -color_normal;
    }
};

class hittable {
  public:
    virtual ~hittable() = default;

    /**
     * @brief Método virtual de interseptação a ser implementado pelas classes filhas
     * 
     * @param r Raio
     * @param ray_t Dados auxiliares de intervalo do raio 
     * @param rec Registro de interseptação
     * @return true 
     * @return false 
     */
    virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;
};

#endif