void sortColors(int* nums, int numsSize){
    int redIndx = 0;
    for (int i = 0; i<numsSize; ++i){
        if (nums[i] == 0){
            int aux = nums[i];
            nums[i] = nums[redIndx];
            nums[redIndx] = aux;
            ++redIndx;
        } 
    }
    for (int i = redIndx; i<numsSize; ++i){
        if (nums[i] == 1){
            int aux = nums[i];
            nums[i] = nums[redIndx];
            nums[redIndx] = aux;
            ++redIndx;
        } 
    }
}