int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int maxSatisfaction(int* satisfaction, int satisfactionSize){
    qsort(satisfaction, satisfactionSize, sizeof(int), cmpfunc);
    int **ans = malloc(satisfactionSize*sizeof(*ans));
    for (int i = 0; i<satisfactionSize; ++i){
        ans[i] = malloc((satisfactionSize-i)*sizeof(int));
    }

    for (int i = 0; i<satisfactionSize; ++i){
        ans[0][i] = satisfaction[i]*(i+1);
    }

    for (int i = 1; i<satisfactionSize; ++i){
        for (int j = i; j<satisfactionSize; ++j){
            ans[i][j-i] = satisfaction[j]*(j-i+1);
        }
    }
    int max = 0;
    for (int i = 0; i<satisfactionSize; ++i){
        int sum = 0;
        for (int j = i; j<satisfactionSize; ++j){
            sum += ans[i][j-i];
        }
        if (sum > max)
            max = sum;
    }
    /* SHOULD FREE USED MEMORY (commented ONLY for better run-time)
    for (int i = 0; i<satisfactionSize; ++i){
        free(ans[i]);
    }
    free(ans);
    */
    
    return max;
}