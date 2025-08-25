class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1=m-1;
        int idx2=n-1, end=m+n-1;
        while(idx2>=0){
            if(idx1>=0 && nums1[idx1]>nums2[idx2]){
                nums1[end]=nums1[idx1];
                idx1--;
            }else{
                nums1[end]=nums2[idx2];
                idx2--;
            }
            end--;
        }
    }
};