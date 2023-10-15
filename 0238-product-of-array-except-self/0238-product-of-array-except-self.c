/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int *ans = calloc(numsSize, sizeof(*ans));
    int pref[numsSize];
    pref[0] = nums[0];
    for (int i = 1; i<numsSize; ++i){
        pref[i] = nums[i]*pref[i-1];
        ans[i] += pref[i-1];
    }
    int suf[numsSize];
    suf[numsSize-1] = nums[numsSize-1];
    for (int i = numsSize-2; i >= 0; --i){
        suf[i] = nums[i]*suf[i+1];
        ans[i] *= suf[i+1];
    }
    ans[0] = suf[1];
    return ans;
}