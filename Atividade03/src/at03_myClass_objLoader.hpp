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
#include <string>
#include <vector>

class myClass_ObjLoader {
   public:
    /**
     * @brief Construtor da classe myClass_ObjLoader
     *
     * @param filename Nome do arquivo de extensão .obj
     */
    myClass_ObjLoader(const std::string& filename) {
        lerArquivoObj(filename);
    }

    /**
     * @brief Imprime as coordenadas x, y e z dos vértices do objeto
     *
     */
    void imprimeVertices() {
        for (const auto& vertex : vertices) {
            std::cout << "Vértice: (" << vertex.x << ", " << vertex.y << ", " << vertex.z << ")\n";
        }
    }

    /**
     * @brief Imprime as coordenadas u e v da textura do objeto
     *
     */
    void imprimeCoordenadasDeTextura() {
        for (const auto& texCoord : textureCoordinates) {
            std::cout << "Coordenadas de Textura: (" << texCoord.u << ", " << texCoord.v << ")\n";
        }
    }

    /**
     * @brief Imprime as coordenadas x, y e z das normais do objeto
     *
     */
    void imprimeNormais() {
        for (const auto& normal : normals) {
            std::cout << "Normal: (" << normal.x << ", " << normal.y << ", " << normal.z << ")\n";
        }
    }

    /**
     * @brief Imprime as informações (vértice, textura e normal) das faces do objeto
     *
     */
    void imprimeFaces() {
        for (const auto& face : faces) {
            std::cout << "Face: ";
            for (const auto& vertex : face) {
                std::cout << vertex.vertexIndex << "/" << vertex.texCoordIndex << "/" << vertex.normalIndex << " ";
            }
            std::cout << "\n";
        }
    }

   public:
    /**
     * @brief Estrutura para armzenar coordenadas x, y e z de um vértice
     *
     */
    struct Vertex {
        float x, y, z;
    };

    /**
     * @brief Estrutura para armazenar coordenadas u e v de uma textura do objeto
     *
     */
    struct TextureCoordinate {
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
    struct FaceVertex {
        int vertexIndex, texCoordIndex, normalIndex;
    };

    // vetores de estruturas do objeto:
    std::vector<Vertex> vertices;
    std::vector<TextureCoordinate> textureCoordinates;
    std::vector<Normal> normals;
    std::vector<std::vector<FaceVertex>> faces;

    /**
     * @brief Lê arquivo de extensão .obj, identificando seu conteúdo e armazenando as informações extraídas em suas respectivas estruturas adequadas
     *
     * @param filename Nome do arquivo de extensão .obj
     */
    void lerArquivoObj(const std::string& filename) {
        std::ifstream file(filename);

        std::string line;

        // enquanto houver linhas no arquivo:
        while (std::getline(file, line)) {
            // identificação de linha de vértice:
            if (line.substr(0, 2) == "v ") {
                Vertex vertex;
                sscanf(line.c_str(), "v %f %f %f", &vertex.x, &vertex.y, &vertex.z);
                vertices.push_back(vertex);

                // identificação de linha de coordenadas de textura:
            } else if (line.substr(0, 3) == "vt ") {
                TextureCoordinate texCoord;
                sscanf(line.c_str(), "vt %f %f", &texCoord.u, &texCoord.v);
                textureCoordinates.push_back(texCoord);

                // identificação de linha de normal:
            } else if (line.substr(0, 3) == "vn ") {
                Normal normal;
                sscanf(line.c_str(), "vn %f %f %f", &normal.x, &normal.y, &normal.z);
                normals.push_back(normal);

                // identificação de linha de face:
            } else if (line.substr(0, 2) == "f ") {
                // vetor de faces:
                std::vector<FaceVertex> faceVertices;

                // armazenamento da linha a partir da quebra (split) em espaços em branco:
                char lineCopy[256];
                strcpy(lineCopy, line.c_str());
                char* token = strtok(lineCopy, " ");

                // leitura de todo o conteúdo da linha:
                while (token != nullptr) {
                    if (token[0] == 'f') {
                        token = strtok(NULL, " ");
                        continue;
                    }

                    // leitura e armazenamento das informações da face, seguidos de continuação da busca:
                    FaceVertex faceVertex;
                    sscanf(token, "%d/%d/%d", &faceVertex.vertexIndex, &faceVertex.texCoordIndex, &faceVertex.normalIndex);
                    faceVertices.push_back(faceVertex);
                    token = strtok(NULL, " ");
                }

                faces.push_back(faceVertices);
            }
        }

        file.close();
    }
};

#endif
