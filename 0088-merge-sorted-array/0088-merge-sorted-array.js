/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
    let i = m-1;
    let j = m+n-1;
    let k = n-1;
    while (k>=0){
        while (nums1[i] >= nums2[k]){
            nums1[j] = nums1[i];
            j--;
            i--;
        }
        nums1[j] = nums2[k];
        j--;
        k--;
    }
    
};