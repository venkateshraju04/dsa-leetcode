class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int resultSum=nums[0]+nums[1]+nums[2];
        int minDiff=INT_MAX;
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==target){
                    return target;
                }else if(sum<target){
                    j++;
                }else{
                    k--;
                }
                int diffToTarget=abs(sum-target);
                if(diffToTarget<minDiff){
                    minDiff=diffToTarget;
                    resultSum=sum;
                }
            }
        }
        return resultSum;
    }
};