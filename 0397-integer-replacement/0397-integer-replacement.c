long long integerReplacement(long long n){
    if (n == INT_MAX)
        return integerReplacement(n-1);
    if(n==1)
        return 0;
    if(!(n%2))
        return integerReplacement(n/2)+1;
    if(n==3||n%4==1)
        return integerReplacement(n-1)+1;

    return integerReplacement(n+1)+1;
}