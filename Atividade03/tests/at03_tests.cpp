#include <gtest/gtest.h>

#include <vector>

#include "../src/at03_myClass_objLoader.hpp"

TEST(at03_tests, TestingObjLoader) {
    myClass_ObjLoader objLoader("/mnt/c/Users/User/Desktop/CG_2023-2/Atividade03/tests/cube.obj");

    // verificando primeiro vértice:
    ASSERT_FLOAT_EQ(objLoader.vertices[0].x, 1);
    ASSERT_FLOAT_EQ(objLoader.vertices[0].y, -1);
    ASSERT_FLOAT_EQ(objLoader.vertices[0].z, -1);

    // verificando sexto vértice:
    ASSERT_FLOAT_EQ(objLoader.vertices[5].x, 0.999999);
    ASSERT_FLOAT_EQ(objLoader.vertices[5].y, 1);
    ASSERT_FLOAT_EQ(objLoader.vertices[5].z, 1.000001);

    // verificando primeira coordenada de textura:
    ASSERT_FLOAT_EQ(objLoader.textureCoordinates[0].u, 0.748573);
    ASSERT_FLOAT_EQ(objLoader.textureCoordinates[0].v, 0.750412);

    // verificando segunda coordenada de textura:
    ASSERT_FLOAT_EQ(objLoader.textureCoordinates[1].u, 0.749279);
    ASSERT_FLOAT_EQ(objLoader.textureCoordinates[1].v, 0.501284);

    // verificando primeira normal:
    ASSERT_FLOAT_EQ(objLoader.normals[0].x, 0);
    ASSERT_FLOAT_EQ(objLoader.normals[0].y, 0);
    ASSERT_FLOAT_EQ(objLoader.normals[0].z, -1);

    // verificando segunda normal:
    ASSERT_FLOAT_EQ(objLoader.normals[1].x, -1);
    ASSERT_FLOAT_EQ(objLoader.normals[1].y, 0);
    ASSERT_FLOAT_EQ(objLoader.normals[1].z, 0);

    // verificando primeira face:
    EXPECT_EQ(objLoader.faces[0][0].vertexIndex, 5);
    EXPECT_EQ(objLoader.faces[0][0].texCoordIndex, 1);
    EXPECT_EQ(objLoader.faces[0][0].normalIndex, 1);

    // verificando segunda face:
    EXPECT_EQ(objLoader.faces[0][1].vertexIndex, 1);
    EXPECT_EQ(objLoader.faces[0][1].texCoordIndex, 2);
    EXPECT_EQ(objLoader.faces[0][1].normalIndex, 1);
}
