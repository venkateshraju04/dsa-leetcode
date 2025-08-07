class Solution {
public:
void findCombination(int idx,int k, int n, vector<int>& subset,vector<vector<int>>& ans){
    if(k==0 && n==0){
        ans.push_back(subset);
        return;
    }
    if(k<=0 || n<=0)return;
    for(int i=idx;i<=9 && i<=n;i++){
        subset.push_back(i);
        findCombination(i+1,k-1,n-i,subset,ans);
        subset.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>subset;
        vector<vector<int>> ans;
        findCombination(1,k,n,subset,ans);
        return ans;
    }
};