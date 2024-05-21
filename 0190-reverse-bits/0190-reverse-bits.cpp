class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int d = 31;
        uint32_t res = 0;
        while (d >= 0){
            res |= ( (n >> d) & 1) << (31 - d);
            --d;
        }
        return res;
    }
};