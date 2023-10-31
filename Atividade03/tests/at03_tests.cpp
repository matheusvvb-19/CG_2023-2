#include <gtest/gtest.h>

#include <vector>

#include "../src/at03_myClass_objLoader.hpp"

TEST(at03_tests, TestingObjLoader) {
    myClass_ObjLoader objLoader;
    objLoader.lerArquivoObj("/mnt/c/Users/User/Desktop/CG_2023-2/Atividade03/tests/cube.obj");

    // verificando primeiro vértice:
    ASSERT_FLOAT_EQ(objLoader.getVertice(0).x, 1);
    ASSERT_FLOAT_EQ(objLoader.getVertice(0).y, -1);
    ASSERT_FLOAT_EQ(objLoader.getVertice(0).z, -1);

    // verificando sexto vértice:
    ASSERT_FLOAT_EQ(objLoader.getVertice(5).x, 0.999999);
    ASSERT_FLOAT_EQ(objLoader.getVertice(5).y, 1);
    ASSERT_FLOAT_EQ(objLoader.getVertice(5).z, 1.000001);

    // verificando primeira coordenada de textura:
    ASSERT_FLOAT_EQ(objLoader.getCoordenadaTextura(0).u, 0.748573);
    ASSERT_FLOAT_EQ(objLoader.getCoordenadaTextura(0).v, 0.750412);

    // verificando segunda coordenada de textura:
    ASSERT_FLOAT_EQ(objLoader.getCoordenadaTextura(1).u, 0.749279);
    ASSERT_FLOAT_EQ(objLoader.getCoordenadaTextura(1).v, 0.501284);

    // verificando primeira normal:
    ASSERT_FLOAT_EQ(objLoader.getNormal(0).x, 0);
    ASSERT_FLOAT_EQ(objLoader.getNormal(0).y, 0);
    ASSERT_FLOAT_EQ(objLoader.getNormal(0).z, -1);

    // verificando segunda normal:
    ASSERT_FLOAT_EQ(objLoader.getNormal(1).x, -1);
    ASSERT_FLOAT_EQ(objLoader.getNormal(1).y, 0);
    ASSERT_FLOAT_EQ(objLoader.getNormal(1).z, 0);

    // verificando primeira face:
    EXPECT_EQ(objLoader.getFace(0, 0).IndiceVertice, 5);
    EXPECT_EQ(objLoader.getFace(0, 0).IndiceTextura, 1);
    EXPECT_EQ(objLoader.getFace(0, 0).IndiceNormal, 1);

    // verificando segunda face:
    EXPECT_EQ(objLoader.getFace(0, 1).IndiceVertice, 1);
    EXPECT_EQ(objLoader.getFace(0, 1).IndiceTextura, 2);
    EXPECT_EQ(objLoader.getFace(0, 1).IndiceNormal, 1);
}
