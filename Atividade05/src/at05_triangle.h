/**
 * @file at05_triangle.h
 * @author Matheus Vargas Volpon Berto
 * @brief Arquivo de implementação da classe Triangle
 * @version 0.1
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "./at05_hittable.h"
#include "./at05_vertex.h"
#include <tuple>

class triangle : public hittable {
    public:
        vertex A;
        vertex B;
        vertex C;
        
        triangle(const vertex& _A, const vertex& _B, const vertex& _C, shared_ptr<material> _material): 
            A(_A), B(_B), C(_C), mat(_material){}
        
        bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
            vec3 e1 = B.coord - A.coord;
            vec3 e2 = C.coord - A.coord;
            vec3 normal_e1e2 = cross(e1, e2);

            double nd = dot(normal_e1e2, r.direction());
            if(fabs(nd) < 1e-8) return false;

            double D = -dot(normal_e1e2, A.coord);
            double t = -(dot(normal_e1e2, r.origin()) + D) / nd;
            
            if(t < 0) return false;

            if(!ray_t.surrounds(t)) return false;

            point3 P = r.at(t);

            vec3 edge0 = B.coord - A.coord; 
            vec3 vp0 = P - A.coord;
            vec3 vp = cross(edge0, vp0);
            if (dot(normal_e1e2, vp) < 0) return false; 
        
            vec3 edge1 = C.coord - B.coord; 
            vec3 vp1 = P - B.coord;
            vp = cross(edge1, vp1);
            if (dot(normal_e1e2, vp) < 0)  return false; 
        
            vec3 edge2 = A.coord - C.coord; 
            vec3 vp2 = P - C.coord;
            vp = cross(edge2, vp2);
            if (dot(normal_e1e2, vp) < 0) return false;

            rec.t = t;
            rec.p = P;
            vec3 color_normal = A.normal;
            rec.set_face_normal(r, A.normal, color_normal);
            rec.mat = mat;

            return true;
        };

    public:
        shared_ptr<material> mat;
};

#endif