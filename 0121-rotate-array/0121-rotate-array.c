void rotate(int* nums, int numsSize, int k){
    int rot[numsSize];
    for (int i = 0; i<numsSize; ++i){
        rot[(k+i) % numsSize] = nums[i];
    }
    for (int i = 0; i<numsSize; ++i){
        nums[i] = rot[i];
    }
}