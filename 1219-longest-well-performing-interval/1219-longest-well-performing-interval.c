int longestWPI(int* hours, int hoursSize){
    int i = 0;
    int max = 0;
    while (i < hoursSize){
        int count = 0;
        int j = i;
        while (j < hoursSize) {
            count += (hours[j] > 8);
            if (j-i+1 < 2*count && j-i+1 > max)
                max = j-i+1;
            ++j;
        }
        ++i;
    }

    return max;
}