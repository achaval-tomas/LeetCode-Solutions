bool isPowerOfFour(int n){
    return n <= 15 ? (n == 4 || n == 1) : (float)round(log2(n)/2) == (float)log2(n)/2.0;
}