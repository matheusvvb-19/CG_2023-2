/**
 * @file projeto_main.cpp
 * @author Arthur Felipe, Guilherme Brante, Lucca Marques, Matheus Volpon
 * @brief Arquivo principal (main) do projeto
 * @version 0.1
 * @date 2024-01-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <vector>
#include <iostream>
#include <string>
#include <cmath>

#include "../../Atividade03/src/at03_myClass_objLoader.hpp"
#include "../../Atividade05/src/at05_camera.h"
#include "../../Atividade05/src/at05_color.h"
#include "../../Atividade05/src/at05_hittable_list.h"
#include "../../Atividade05/src/at05_material.h"
#include "../../Atividade05/src/at05_sphere.h"
#include "../../Atividade05/src/at05_triangle.h"
#include "../../Atividade05/src/at05_utils.h"

int main() {
    // Coordenadas de centro das esferas presentes na cena (esfera da esquerda e esfera da direita, respectivamente):
    float coordX_leftSphere = -4;
    float coordX_rightSphere = 2;
    float passo = 0.2;

    // Criação e configuração inicial da câmera:
    camera cam1;
    cam1.aspect_ratio = 16.0 / 9.0;
    cam1.image_width = 144;
    cam1.samples_per_pixel = 10;
    cam1.max_depth = 20;

    cam1.vfov = 30;
    cam1.lookfrom = point3(0, 5, 20);
    cam1.lookat = point3(0, 0, 0);
    cam1.vup = vec3(0, 1, 0);

    cam1.defocus_angle = 0.6;
    cam1.focus_dist = 10.0;

    // Geração de cada frame da cena
    // a animação contém 5 segundos, sendo cada segundo composto por 10 frames. Portanto, 50 frames deverão ser produzidos:
    for (int frame = 0; frame < 50; frame++) {
        // Lista de objetos atingíveis (hittable), compondo o mundo da cena:
        hittable_list world;

        // Adição do "chão" (ou background):
        auto ground_material = make_shared<lambertian>(color(0.5, 0.5, 0.5));
        world.add(make_shared<sphere>(point3(0, -1000, 0), 1000, ground_material));

        // Inserção do cubo rosa central da cena, a partir de leitura de arquivo .obj:
        myClass_ObjLoader obj;
        obj.lerArquivoObj("./cube.obj");
        auto cube_material = make_shared<metal>(color(0.9, 0.1, 0.3), 0.2);

        vector<triangle> triangles_list = obj.get_triangle_faces(cube_material);
        for (int i = 0; i < triangles_list.size(); i++) {
            // ajuste de coordenadas do cubo (arquivo obj) de forma a posicioná-lo corretamente na cena:
            vertex v0 = triangles_list[i].A;
            v0.coord = v0.coord.operator+=(point3(0, 1, 0));

            vertex v1 = triangles_list[i].B;
            v1.coord = v1.coord.operator+=(point3(0, 1, 0));

            vertex v2 = triangles_list[i].C;
            v2.coord = v2.coord.operator+=(point3(0, 1, 0));
            world.add(make_shared<triangle>(v0, v1, v2, triangles_list[i].mat));
        }

        // Inserção de esfera à esquerda do cubo:
        auto material2 = make_shared<lambertian>(color(1, 0.7, 0.5));
        world.add(make_shared<sphere>(point3(coordX_leftSphere, 1, 0), 1.0, material2));

        // Inserção de esfera à direita do cubo:
        auto material1 = make_shared<dielectric>(2);//color(0.4, 0.2, 0.1)
        world.add(make_shared<sphere>(point3(coordX_rightSphere, 1, 0), 1.0, material1));

        // Rendereização e escrita do frame:
        std::string filename = "cam" + std::to_string(frame) + ".ppm";
        cam1.render(world, filename);

        // Atualização das coordenadas das esferas e da câmera, gerando movimento:
        // movimento horizontal (eixo x) da esfera à esquerda, entre as posições -4 e -2:
        if (((floor(frame/10) == 0) || (floor(frame/10) == 2) || (floor(frame/10) == 4)) && coordX_leftSphere < -2) {
            coordX_leftSphere += passo;

        } else {
            coordX_leftSphere -= passo;
            
        }

        // movimento horizontal (eixo x) da esfera à direita, entre as posições 2 e 4:
        if (((floor(frame/10) == 1) || (floor(frame/10) == 3))) {
            coordX_rightSphere -= passo;

        } else {
            coordX_rightSphere += passo;
        }

        // Movimento da câmera:
        if (frame <= 24) {
            cam1.lookfrom = cam1.lookfrom.operator+=(point3(1, 0.5, -1));
            cam1.vup = cam1.vup.operator+=(point3(0, 0.5, 0));

        } else {
            cam1.lookfrom = cam1.lookfrom.operator+=(point3(-1, -0.5, 1));
            cam1.vup = cam1.vup.operator+=(point3(0, -0.5, 0));
        }
    }
}
