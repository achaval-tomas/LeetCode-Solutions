bool search(int* nums, int numsSize, int target){
    if (nums[0] == target || nums[numsSize-1] == target || nums[numsSize/2] == target)
        return true;
    if (numsSize == 1 && nums[0] != target)
        return false;
    return search(&nums[numsSize/2], numsSize/2, target) || search(nums, numsSize/2, target);
}