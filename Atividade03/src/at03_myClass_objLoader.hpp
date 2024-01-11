/**
 * @file at03_myClass_objLoader.hpp
 * @author Matheus Vargas Volpon Berto
 * @brief Arquivo de implementação da classe myClass_ObjLoader
 * @version 0.1
 * @date 2023-10-25
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef OBJ_LOADER
#define OBJ_LOADER

#include <cstring>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <cmath>

#include "../../Atividade05/src/at05_triangle.h"
#include "../../Atividade05/src/at05_material.h"

using namespace std;

class myClass_ObjLoader {
   public:
    /**
     * @brief Construtor da classe myClass_ObjLoader
     *
     * @param filename Nome do arquivo de extensão .obj
     */
    myClass_ObjLoader() {
        vertices = std::vector<Vertice>();
        coordenadasTextura = std::vector<CoordenadaTextura>();
        normais = std::vector<Normal>();
        faces = std::vector<std::vector<VerticesDeFace>>();
    }

   public:
    /**
     * @brief Estrutura para armzenar coordenadas x, y e z de um vértice
     *
     */
    struct Vertice {
        float x, y, z;
    };

    /**
     * @brief Estrutura para armazenar coordenadas u e v de uma textura do objeto
     *
     */
    struct CoordenadaTextura {
        float u, v;
    };

    /**
     * @brief Estrutura para armazenar as coordenadas x, y e z da normal de um objeto
     *
     */
    struct Normal {
        float x, y, z;
    };

    /**
     * @brief Estrutura para armazenar informações da face de um objeto
     *
     */
    struct VerticesDeFace {
        int IndiceVertice, IndiceTextura, IndiceNormal;
    };

    // vetores de estruturas do objeto:
    std::vector<Vertice> vertices;
    std::vector<CoordenadaTextura> coordenadasTextura;
    std::vector<Normal> normais;
    std::vector<std::vector<VerticesDeFace>> faces;

   public:
    /**
     * @brief Retorna um vértice do vetor de vértices em um determinado índice
     *
     * @param idx Índice desejado
     * @return Vertice
     */
    Vertice getVertice(const int idx) {
        if (idx >= 0 && idx < this->vertices.size()) {
            return this->vertices[idx];
        }

        return Vertice();
    };

    /**
     * @brief Retorna uma coordenada de textura do vetor de coordenadas de textura em um determinado índice
     *
     * @param idx Índice desejado
     * @return CoordenadaTextura
     */
    CoordenadaTextura getCoordenadaTextura(const int idx) {
        if (idx >= 0 && idx < this->coordenadasTextura.size()) {
            return this->coordenadasTextura[idx];
        }

        return CoordenadaTextura();
    };

    /**
     * @brief Retorna uma normal do vetor de normais em um determinado índice
     *
     * @param idx Índice desejado
     * @return Normal
     */
    Normal getNormal(const int idx) {
        if (idx >= 0 && idx < this->normais.size()) {
            return this->normais[idx];
        }

        return Normal();
    };

    /**
     * @brief Retorna uma face do vetor de faces em um determinado índice i e j
     *
     * @param i Primeiro índice desejado
     * @param j Segundo índice desejado
     * @return VerticesDeFace
     */
    VerticesDeFace getFace(const int i, const int j) {
        if (i >= 0 && j >= 0 && i < this->faces.size()) {
            return this->faces[i][j];
        }

        return VerticesDeFace();
    };

    /**
     * @brief Lê arquivo de extensão .obj, identificando seu conteúdo e armazenando as informações extraídas em suas respectivas estruturas adequadas
     *
     * @param filename Nome do arquivo de extensão .obj
     */
    void lerArquivoObj(const std::string& filename) {
        std::ifstream file(filename);

        std::string line;
        std::regex regexVertex("^v (-?\\d+\\.\\d+) (-?\\d+\\.\\d+) (-?\\d+\\.\\d+)");
        std::regex regexTexCoord("^vt (-?\\d+\\.\\d+) (-?\\d+\\.\\d+)");
        std::regex regexNormal("^vn (-?\\d+\\.\\d+) (-?\\d+\\.\\d+) (-?\\d+\\.\\d+)");
        std::regex regexFace("^f (\\d+)/(\\d+)/(\\d+) (\\d+)/(\\d+)/(\\d+) (\\d+)/(\\d+)/(\\d+)");

        while (std::getline(file, line)) {
            if (std::regex_match(line, regexVertex)) {
                Vertice vertex;
                sscanf(line.c_str(), "v %f %f %f", &vertex.x, &vertex.y, &vertex.z);
                vertices.push_back(vertex);

            } else if (std::regex_match(line, regexTexCoord)) {
                CoordenadaTextura texCoord;
                sscanf(line.c_str(), "vt %f %f", &texCoord.u, &texCoord.v);
                coordenadasTextura.push_back(texCoord);

            } else if (std::regex_match(line, regexNormal)) {
                Normal normal;
                sscanf(line.c_str(), "vn %f %f %f", &normal.x, &normal.y, &normal.z);
                normais.push_back(normal);

            } else if (std::regex_match(line, regexFace)) {
                std::vector<VerticesDeFace> faceVertices;
                std::smatch matches;
                if (std::regex_search(line, matches, regexFace)) {
                    for (size_t i = 1; i < matches.size(); i += 3) {
                        VerticesDeFace faceVertex;
                        faceVertex.IndiceVertice = std::stoi(matches[i]);
                        faceVertex.IndiceTextura = std::stoi(matches[i + 1]);
                        faceVertex.IndiceNormal = std::stoi(matches[i + 2]);
                        faceVertices.push_back(faceVertex);
                    }
                }
                faces.push_back(faceVertices);
            }
        }

        file.close();
    };

    vector<triangle> get_triangle_faces(shared_ptr<material> mat) {
        /* Collect all triangles from obj */
        vector<triangle> triangle_list;
        int qtd_faces = this->faces.size();

        for (size_t i = 0; i < qtd_faces; i++) {
            int indiceV0 = this->getFace(i, 0).IndiceVertice - 1;
            int indiceV1 = this->getFace(i, 1).IndiceVertice - 1;
            int indiceV2 = this->getFace(i, 2).IndiceVertice - 1;

            point3 A(this->getVertice(indiceV0).x, this->getVertice(indiceV0).y, this->getVertice(indiceV0).z);
            point3 B(this->getVertice(indiceV1).x, this->getVertice(indiceV1).y, this->getVertice(indiceV1).z);
            point3 C(this->getVertice(indiceV2).x, this->getVertice(indiceV2).y, this->getVertice(indiceV2).z);

            // If the obj file doesn't specify vertex normals...
            if(normais.empty()) {
                vec3 u = B - A;
                vec3 v = C - A;
                vec3 triangle_normal = cross(u, v);

                vertex vA(A, triangle_normal), vB(B, triangle_normal), vC(C, triangle_normal);
                triangle t = triangle(vA, vB, vC, mat);
                triangle_list.push_back(t);

            } else {
                int ind_vnA = this->getFace(i, 0).IndiceNormal - 1;
                int ind_vnB = this->getFace(i, 1).IndiceNormal - 1;
                int ind_vnC = this->getFace(i, 2).IndiceNormal - 1;
                point3 normal_A(this->getNormal(ind_vnA).x, this->getNormal(ind_vnA).y, this->getNormal(ind_vnA).z);
                point3 normal_B(this->getNormal(ind_vnB).x, this->getNormal(ind_vnB).y, this->getNormal(ind_vnB).z);
                point3 normal_C(this->getNormal(ind_vnC).x, this->getNormal(ind_vnC).y, this->getNormal(ind_vnC).z);

                vertex vA(A, normal_A), vB(B, normal_B), vC(C, normal_C);
                triangle t = triangle(vA, vB, vC, mat);
                triangle_list.push_back(t);
            }
        }

        return triangle_list;
    }
};

#endif
