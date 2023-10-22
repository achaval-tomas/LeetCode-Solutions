int countPrimes(int n){
    if (n <= 1)
        return 0;
    bool list[n];
    for (int i = 0; i<n;++i){
        list[i] = true;
    }
    int sq = ceil(sqrt(n));
    for (int i = 2; i<sq; ++i){
        if (list[i]){
            for (int j = i*i; j<n; j+=i){
                list[j] = false;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; ++i<n;)
        cnt += list[i];
    return cnt;
}