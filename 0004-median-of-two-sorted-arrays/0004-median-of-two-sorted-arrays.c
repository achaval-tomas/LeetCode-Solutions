double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    if (nums1Size == 0 && nums2Size == 0){
        return 0;
    }
    int totalLength = nums1Size + nums2Size;

    int len = totalLength/2+1;
    double merged[len];
    int i = 0;
    int j = 0;
    while (i+j < len){
        if (i<nums1Size && j<nums2Size && nums1[i] < nums2[j]){
            merged[i+j] = nums1[i];
            ++i;
        } else if (j<nums2Size){
            merged[i+j] = nums2[j];
            ++j;
        } else if (i<nums1Size){
            merged[i+j] = nums1[i];
            ++i;
        }
    }

    return (totalLength%2) ? merged[len-1] : (merged[len-1] + merged[len-2]) / 2;
}