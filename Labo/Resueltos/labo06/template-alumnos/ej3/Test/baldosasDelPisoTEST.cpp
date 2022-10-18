#include "../baldosasDelPiso.h"
#include "gtest/gtest.h"

TEST(baldosasTest, ambosDivPorB){
    EXPECT_EQ(baldosasDelPiso(4, 8, 2), 8);
    EXPECT_EQ(baldosasDelPiso(77, 45, 1), 3465);
}

TEST(baldosasTest, soloMDivPorB){
    EXPECT_EQ(baldosasDelPiso(8, 4, 8), 1);
    EXPECT_EQ(baldosasDelPiso(14, 3, 7), 2);
}

TEST(baldosasTest, soloNDivPorB){
    EXPECT_EQ(baldosasDelPiso(5, 15, 3), 10);
    EXPECT_EQ(baldosasDelPiso(7, 10, 5), 4);
}

TEST (baldosasTest, ningunoDivPorB){
    EXPECT_EQ(baldosasDelPiso(13, 7, 3), 15);
    EXPECT_EQ(baldosasDelPiso(6, 6, 4), 4);
    EXPECT_EQ(baldosasDelPiso(5, 3, 2), 6);

}