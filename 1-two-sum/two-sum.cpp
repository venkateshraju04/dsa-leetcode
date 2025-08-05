class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            int need=target-nums[i];
            if(map.find(need)!=map.end())return {i, map[need]};
            map[nums[i]]=i;
        }
        return {};
    }
};