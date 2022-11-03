#include "../contandoDragones.h"
#include "gtest/gtest.h"

TEST (dragonesAfectadosTest, coprimos){
    EXPECT_EQ(contandoDragones(7,3,4,5), 4);
    EXPECT_EQ(contandoDragones(17,7,2,9), 10);
}

TEST (dragonesAfectadosTest, noCoprimos){
    EXPECT_EQ(contandoDragones(19,2,21,6), 9);
    EXPECT_EQ(contandoDragones(22,2,15,5), 13);
}

