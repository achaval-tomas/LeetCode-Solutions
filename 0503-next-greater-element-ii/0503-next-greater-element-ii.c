/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    int *ans = malloc(numsSize*sizeof(*ans));
    for (int i = 0; i<numsSize; ++i){
        int j = i+1;
        while (i != j%numsSize && nums[i] >= nums[j%numsSize])
            ++j;
        if (i == j%numsSize){
            ans[i] = -1;
            continue;
        }
        ans[i] = nums[j%numsSize];
    }
    *returnSize = numsSize;
    return ans;
}