/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int countBits(int x){
    int c = 0;
    int mask = 0x1;
    while (x!=0){
        c += (x&mask);
        x = x>>1;
    }
    return c;
}

int* sortByBits(int* arr, int arrSize, int* returnSize){
    *returnSize = arrSize;
    for (int i = 0; i<arrSize; ++i){
        for (int j = 0; j<arrSize; ++j){
            int bitsA = countBits(arr[i]);
            int bitsB = countBits(arr[j]);
            if (bitsA <= bitsB){
                int aux = (bitsA != bitsB) ? arr[i] : ((arr[i]<arr[j]) ? arr[i] : arr[j]);
                arr[i] = (aux == arr[i]) ? arr[j] : arr[i];
                arr[j] = (arr[j] == arr[i]) ? aux : arr[j];
            }
        }
    }
    return arr;
}