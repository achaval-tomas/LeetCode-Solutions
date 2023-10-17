int numberOfBeams(char ** bank, int bankSize){
    int beams = 0;
    int *devPerRow = calloc(bankSize, sizeof(*devPerRow));
    for (int i = 0; i<bankSize; ++i){
        int len = strlen(bank[i]);
        for (int j = 0; j<len; ++j){
            devPerRow[i] += (bank[i][j] == '1');
        }
    }
    int i = 0;
    while (i<bankSize){
        int j = i+1;
        while (j<bankSize && devPerRow[j] == 0)
            ++j;
        if (j<bankSize)
            beams += devPerRow[i]*devPerRow[j];
        i = j;
    }

    free(devPerRow);
    return beams;
}