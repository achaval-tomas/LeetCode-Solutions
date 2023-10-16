/**
 * Note: The returned array must be malloced, assume caller calls free().
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

int* getRow(int rowIndex, int* returnSize){
    int *ans = malloc((1+rowIndex)*sizeof(*ans));
    *returnSize = rowIndex+1;
    for (int i = 0; i<=*returnSize/2; ++i){
        int val = comb(rowIndex, i);
        ans[i] = val;
        ans[*returnSize-1-i] = val;
    }   
    return ans;
}