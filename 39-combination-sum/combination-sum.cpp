class Solution {
public:
void findCombination(int idx,vector<int>& candidates, int target,vector<int>& subset,vector<vector<int>>& ans){
        if(idx==candidates.size()){
            if(target==0){ans.push_back(subset);}
            return;
        }
        if(candidates[idx]<=target){
            subset.push_back(candidates[idx]);
            findCombination(idx,candidates,target-candidates[idx],subset,ans);
            subset.pop_back();
        }
        findCombination(idx+1,candidates,target,subset,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>subset;
        vector<vector<int>> ans;
        findCombination(0,candidates,target,subset,ans);
        return ans;
    }

};