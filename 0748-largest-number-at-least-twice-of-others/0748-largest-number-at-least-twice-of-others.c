int dominantIndex(int* nums, int numsSize){
    int max = 0;
    for (int i = 1; i<numsSize; ++i){
        max = nums[i] > nums[max] ? i : max;
    }
    for (int i = 0; i<numsSize; ++i){
        if (i!=max && nums[max]<2*nums[i])
            return -1;
    }
    return max;
}