class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k= m+n-1;

        while(j>=0){
            if(i>=0 && nums1[i]>nums2[j]){
                nums1[k--]=nums1[i--];
            }
            else{
                nums1[k--]=nums2[j--];
            }
        }


        // vector<int> ans(m + n);
        // int index1 = 0;
        // int index2 = 0;
        // int mainIndex = 0;
        // // compare both until each have indexing validation
        // while (index1 < m && index2 < n) {
        //     if (nums1[index1] < nums2[index2]) {
        //         ans[mainIndex++] = nums1[index1++];
        //     } else {
        //         ans[mainIndex++] = nums2[index2++];
        //     }
        // }
        // // nums1 remaining entries
        // while (index1 < m) {
        //     ans[mainIndex++] = nums1[index1++];
        // }
        // // nums2 remaining entries
        // while (index2 < n) {
        //     ans[mainIndex++] = nums2[index2++];
        // }
        // nums1 = ans;
    }
};