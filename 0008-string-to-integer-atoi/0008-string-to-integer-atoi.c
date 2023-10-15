int myAtoi(char * s){
    int i = 0;
    int len = strlen(s);
    while(i<len && s[i] == ' ')
        ++i;
    
    int sign = 1;
    if (i<len && s[i] == '-'){
        sign = -1;
        ++i;
    } else if (i<len && s[i] == '+'){
        sign = 1;
        ++i;
    }

    int j = i;
    while(j<len && s[j] >= '0' && s[j] <= '9'){
        ++j;
    }
    double num = 0;
    double p = pow(10, j-i-1);

    while (i<j){
        num += (s[i] - 48)*p;
        p *= 0.1;
        ++i;
    }

    num *= sign;
    if (num > INT_MAX)
        return INT_MAX;
    if (num < INT_MIN)
        return INT_MIN;
    return num;
}