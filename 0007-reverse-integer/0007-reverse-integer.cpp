class Solution {
public:
    int reverse(int x) {
        int isNeg = 1;
        if (x == 0 || x == INT_MIN){
            return 0;
        } else if (x < 0){
            isNeg = -1;
            x = abs(x);
        }

        int log10x = floor(log10(x));
        long long reversed = 0;

        for (int i = 1; i <= log10x+1; ++i) {
            long long value = x % (long long)pow(10, i);
            reversed += (value / pow(10, i-1)) * pow(10, log10x + 1 - i);
            x -= value;
        }

        if (reversed < INT_MIN || reversed > INT_MAX) {
            return 0;
        }

        return isNeg*reversed;
    }
};