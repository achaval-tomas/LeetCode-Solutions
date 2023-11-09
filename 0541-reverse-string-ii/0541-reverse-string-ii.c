char* reverseStr(char* s, int k) {
    int len = strlen(s);
    for (int i = 0; i<len; i += 2*k){
        if (i+k > len)
            k = len-i; // reverse last remaining chars
        for (int j = 0; j<k/2 && i+j<len; ++j){
            char aux = s[i+j];
            s[i+j] = s[i+k-j-1];
            s[i+k-j-1] = aux;
        }
    }
    return s;
}
