/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int comb(int n, int k){
    if (k == 0)
        return 1;
    if (k == 1)
        return n;
    long double res = 1;
    while (n>k){
        res *= (long double)n/(n-k);
        --n;
    }
    return round(res);
}

int* getRow(int rowIndex){
    int size = rowIndex+1;
    int *ans = malloc(size*sizeof(*ans));
    for (int i = 0; i<=size/2; ++i){
        int val = comb(rowIndex, i);
        ans[i] = val;
        ans[size-1-i] = val;
    }   
    return ans;
}

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int ** ans = malloc(numRows*sizeof(*ans));
    *returnSize = numRows;
    *returnColumnSizes = malloc(numRows*sizeof(*ans));
    for (int i = 0; i<numRows; ++i){
        ans[i] = getRow(i);
        (*returnColumnSizes)[i] = i+1;
    }

    return ans;
}