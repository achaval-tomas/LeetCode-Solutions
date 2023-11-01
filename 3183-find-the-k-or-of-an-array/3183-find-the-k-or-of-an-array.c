int findKOr(int* nums, int numsSize, int k) {
    long mask = 0x1;
    int kOR = 0;
    while( mask <= INT_MAX ){
        int count = 0;
        // Check for k numbers with the same bit set as mask.
        for (int j = 0; j<numsSize && count<k; ++j)
            count += (bool)(nums[j] & mask);

        // If there were k numbers, add mask to the final answer.
        if (count == k)
            kOR += mask; 

        // Shift Left mask to check the next bit.
        mask = mask << 1;
    }
    return kOR;
}
