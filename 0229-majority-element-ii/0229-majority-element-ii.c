/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize){
    int count = 0;
    int *elems = malloc(3*sizeof(*elems));
    int init = 0;
    *returnSize = 0;
    for (int i = 0; i < numsSize; ++i){
        bool found = false;
        int num = nums[i];
        count = 1;
        for (int k = 0; k < 3; ++k){
            if (num == elems[k])
                found = true;
        }
        for (int j = i+1; j < numsSize && count <= numsSize/3 && !found; ++j){
            count += (num == nums[j]);
        }
        if (count > numsSize/3 && !found && init < 3){
            elems[init] = num;
            ++init;
        }
    }
    *returnSize = init;
    return elems;
}