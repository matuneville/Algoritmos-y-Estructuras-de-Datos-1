#include "../puntaje.h"
#include "gtest/gtest.h"

TEST(puntajeTest, menorQue10){
    EXPECT_EQ(puntaje(8), 6);
    EXPECT_EQ(puntaje(7), 4);
    EXPECT_EQ(puntaje(2), -6);
}

TEST(puntajeTest, menorQue10yMultiploDe3){
    EXPECT_EQ(puntaje(9), 28);
    EXPECT_EQ(puntaje(3), 16);
    EXPECT_EQ(puntaje(-27), -44);
}

TEST(puntajeTest, mayorQue10){
    EXPECT_EQ(puntaje(13), 3);
    EXPECT_EQ(puntaje(3931), 3921);
}

TEST(puntajeTest, mayorQue10yMultiploDe3){
    EXPECT_EQ(puntaje(24), 34);
    EXPECT_EQ(puntaje(3930), 3940);
    EXPECT_EQ(puntaje(18), 28);
}

//asi ya recorri todas las lineas y branches