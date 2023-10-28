int hammingDistance(int x, int y){
    int diff = x ^ y;
    long mask = 0x00000001;
    int cnt = 0;
    while (mask != 0x80000000){
        cnt += (diff & mask) ? 1 : 0;
        mask = mask << 1;
    }
    return cnt;
}