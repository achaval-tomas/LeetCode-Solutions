int minOperations(int* nums, int numsSize){
    int sum = 0;
    for (int i = 0; i<numsSize-1; ++i){
        if (nums[i] >= nums[i+1]){
            sum += nums[i] - nums[i+1] + 1;
            nums[i+1] += nums[i]-nums[i+1]+1;
        }
    }
    return sum;
}