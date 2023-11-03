bool isPowerOfThree(double n) {
    return n <= 0 ? false : n == 1 ? true : isPowerOfThree((double)n/3);
}