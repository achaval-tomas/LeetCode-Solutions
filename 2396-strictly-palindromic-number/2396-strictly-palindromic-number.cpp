class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        for (int i = 2; i <= n - 2; ++i){
            if (!isPalindromic(baseBasString(n, i)))
                return false;
        }
        return true;
    }

    bool isPalindromic(std::string s) {
        for (int i = 0; i <= s.size() / 2; ++i) {
            if (!(s[i] == s[s.size() - 1 - i]))
                return false;
        }
        return true;
    }

    std::string baseBasString(int n, int B) {
        std::string result = "";
        while (n > 0) {
            result = std::to_string(n % B) + result;
            n /= B;
        }
        return result;
    }
};