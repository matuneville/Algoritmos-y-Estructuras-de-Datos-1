
int contandoDragones(int T, int x, int y, int z) {

    int dragonesAfectados = 0;

    for (int i = 1; i <= T; i++){

        if (i % x == 0 ||
            i % y == 0 ||
            i % z == 0) {
            dragonesAfectados++;
        }
    }

    return dragonesAfectados;
}
