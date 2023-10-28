int candy(int* ratings, int ratingsSize){
    int *a = calloc(ratingsSize, sizeof(*a));  // initialized with all 0s.
    /* 
     * Count children who have more rating than their left neighbor, 
     * and mark them in accumulative fashion to account for extra candies needed.
     */
    for (int i = 1; i<ratingsSize; ++i){
        if (ratings[i]>ratings[i-1])
            a[i] = a[i-1]+1;
    }
    /* 
     * Count children who have more rating than their right neighbor, 
     * and mark those who haven't been marked yet in accumulative fashion.
     */
    for (int i = ratingsSize-2; i>=0; --i){
       if (ratings[i]>ratings[i+1]){
            if (a[i]<=a[i+1]) // only give extra candies to those who've not been given enough already.
                a[i] = a[i+1]+1;
        }
    }
    /* 
     *  At this point, a[i] holds the amount of candies needed to make 
     *  the i-th child meet the requirements. 
     */
    int ans = ratingsSize; // each child must have at least one candy.
    for (int i = 0; i<ratingsSize; ++i){
        ans += a[i];  // sum of all extra candies needed.
    }
    return ans;
}