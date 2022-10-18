int baldosasDelPiso(int M, int N, int B) {
    int widthTiles = 0, heightTiles = 0;

	do {
        M -= B;
        widthTiles++;
    } while (M > 0);

    do {
        N -= B;
        heightTiles++;
    } while (N > 0);

    int tiles = widthTiles * heightTiles;

    return tiles;
}
