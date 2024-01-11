/**
 * @file at05_hittable_list.h
 * @author Matheus Vargas Volpon Berto
 * @brief Arquivo de implementação da classe Hittable_list
 * @version 0.1
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "./at05_utils.h"
#include "./at05_hittable.h"
#include <memory>
#include <vector>

class hittable_list : public hittable {
  public:
    std::vector<shared_ptr<hittable>> objects;

    hittable_list() {}
    hittable_list(shared_ptr<hittable> object) { add(object); }

    /**
     * @brief Elimina todos os objetos interceptáveis armazenados
     * 
     */
    void clear() { objects.clear(); }

    /**
     * @brief Adiciona um novo objeto na lista de objetos interceptáveis da cena
     * 
     * @param object 
     */
    void add(shared_ptr<hittable> object) {
        objects.push_back(object);
    }

    /**
     * @brief Função que verifica se algum dos objetos intercepta algo na cena
     * 
     * @param r Raio
     * @param ray_t Dados auxiliares de intervalo do raio
     * @param rec Estrutura para armazenamento de interceptações
     * @return true 
     * @return false 
     */
    bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
        hit_record temp_rec;
        auto hit_anything = false;
        auto closest_so_far = ray_t.max;

        for (const auto& object : objects) {
            if (object->hit(r, interval(ray_t.min, closest_so_far), temp_rec)) {
                hit_anything = true;
                closest_so_far = temp_rec.t;
                rec = temp_rec;
            }
        }

        return hit_anything;
    }
};


#endif