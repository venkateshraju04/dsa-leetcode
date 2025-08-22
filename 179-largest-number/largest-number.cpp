class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int a,int b){
            return (to_string(b)+to_string(a))<(to_string(a)+to_string(b));
        });
        if(nums[0]==0)return "0";
        string largest;
        for(auto num:nums){
            largest+=to_string(num);
        }
        return largest;
    }
};