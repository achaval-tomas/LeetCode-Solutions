int gcdiv(int a, int b){
    int i = a < b ? a : b;
    while (i>1 && (a%i || b%i)){
        --i;
    }
    return i;
}

bool isGoodArray(int* nums, int numsSize){
    int gcd = nums[0];
    for (int i = 1; i<numsSize;++i){
        gcd = gcdiv(gcd, nums[i]);
        if (gcd == 1)
            return true;
    }
    return gcd == 1 ? true : false;
}