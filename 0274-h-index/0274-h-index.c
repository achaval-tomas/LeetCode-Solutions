int cmpfunc(const void *a, const void *b)
{
    return(*(int*)a - *(int*)b);
}

int hIndex(int* citations, int citationsSize){

    qsort(citations, citationsSize, sizeof(int), cmpfunc);

    if (citations[0] >= citationsSize){
        return citationsSize;
    } else if (citationsSize > 1){
        return hIndex(&citations[1], citationsSize-1);
    }

    return 0;
}