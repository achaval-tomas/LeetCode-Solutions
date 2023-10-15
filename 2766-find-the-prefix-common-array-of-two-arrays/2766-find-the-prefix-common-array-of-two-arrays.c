/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize){
    *returnSize = ASize;
    int *ans = malloc(*returnSize*sizeof(*ans));
    ans[0] = A[0] == B[0];
    for (int i = 1; i<ASize; ++i){
        int count = (A[i] == B[i]);
        for (int j = 0; j<i; ++j){
            count += (A[i] == B[j]);
            count += (A[j] == B[i]);
        }
        ans[i] = ans[i-1] + count;
    }
    return ans;
}