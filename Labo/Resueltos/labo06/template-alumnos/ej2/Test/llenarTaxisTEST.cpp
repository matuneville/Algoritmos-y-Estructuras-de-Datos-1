#include "../llenarTaxis.h"
#include "gtest/gtest.h"

TEST(llenarTaxisTest, todosIguales){
    EXPECT_EQ(llenarTaxis1(8,8,8),12);
    EXPECT_EQ(llenarTaxis2(8,8,8),12);
    EXPECT_EQ(llenarTaxis3(8,8,8),12);
}

TEST(llenarTaxisTest, CuatroDosUno){
    EXPECT_EQ(llenarTaxis1(4,2,1),3);
    EXPECT_EQ(llenarTaxis2(4,2,1),3);
    EXPECT_EQ(llenarTaxis3(4,2,1),3);
}

TEST(llenarTaxisTest, DosTresUno){
    EXPECT_EQ(llenarTaxis1(2,3,1),3);
    EXPECT_EQ(llenarTaxis2(2,3,1),3);
    EXPECT_EQ(llenarTaxis3(2,3,1),3);
}

TEST(llenarTaxisTest, CuatroTresUno){
    EXPECT_EQ(llenarTaxis1(4,3,1),4);
    EXPECT_EQ(llenarTaxis2(4,3,1),4);
    EXPECT_EQ(llenarTaxis3(4,3,1),4);
}