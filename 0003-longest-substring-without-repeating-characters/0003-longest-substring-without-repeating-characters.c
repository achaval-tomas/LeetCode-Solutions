int included(char * s, char c, int i, int j){
    for (int k = i; k<j; ++k){
        if (s[k] == c)
            return 1;
    }
    return 0;
}


int lengthOfLongestSubstring(char * s){
    int longestSubstr = 0;
    int j = 0;
    for (int i = 0; s[i] != '\0'; ++i){
        j = i+1;
        while (s[j] != '\0' && !included(s, s[j], i, j)){
            ++j;
        }
        if (j-i > longestSubstr)
            longestSubstr = j-i;
    }
    return longestSubstr;
}