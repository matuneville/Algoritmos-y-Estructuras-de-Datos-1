#include "../electores.h"
#include "gtest/gtest.h"

TEST (electoresTest, votanteObligatorio){
    EXPECT_EQ(validarVotante(13, 10, 2002), OBLIGATORIO);
    EXPECT_EQ(validarVotante(6, 4, 1973), OBLIGATORIO);
}

TEST (electoresTest, votanteOpcionalMenorOMayor){
    EXPECT_EQ(validarVotante(1, 12, 1951), OPCIONAL_MAYOR);
    EXPECT_EQ(validarVotante(16, 3, 2005), OPCIONAL_MENOR);
}

TEST (electoresTest, noVota){
    EXPECT_EQ(validarVotante(29, 9, 2010), NO_VOTA);
    EXPECT_EQ(validarVotante(23, 7, 2021), NO_VOTA);
}

TEST (electoresTest, fechaInvalida){
    EXPECT_EQ(validarVotante(130, 10, 2002), ERROR);
    EXPECT_EQ(validarVotante(24, 12, 2023), ERROR);
}