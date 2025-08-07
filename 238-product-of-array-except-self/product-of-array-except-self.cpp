class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>output(n,1);
        int prefix=1,postfix=1;
        for(int i=0;i<n;i++){
            output[i]=prefix*output[i];
            prefix*=nums[i];
        }
        for(int i=n-1;i>=0;i--){
            output[i]=postfix*output[i];
            postfix*=nums[i];
        }
        return output;
    }
};