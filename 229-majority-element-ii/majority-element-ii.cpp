class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int majority1=INT_MIN, majority2=INT_MIN;
        int cnt1=0,cnt2=0;
        for(int num:nums){
            if(cnt1==0 && num!=majority2){
                majority1=num;
                cnt1++;
            }else if(cnt2==0 && num!=majority1){
                majority2=num;
                cnt2++;
            }else if(num==majority1){
                cnt1++;
            }else if(num==majority2){
                cnt2++;
            }else{
                cnt1--,cnt2--;
            }
        }
        cnt1=0, cnt2=0;
        for(int num:nums){
            if(num==majority1)cnt1++;
            else if(num==majority2)cnt2++;
        }
        vector<int>ans;
        int n=nums.size();
        if(cnt1>n/3)ans.push_back(majority1);
        if(cnt2>n/3)ans.push_back(majority2);
        return ans;
    }
};