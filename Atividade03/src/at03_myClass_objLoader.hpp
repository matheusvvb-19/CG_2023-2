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
    }
};

#endif
