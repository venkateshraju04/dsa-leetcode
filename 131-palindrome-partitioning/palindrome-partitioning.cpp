class Solution {
public:
    bool isPalindrome(int start,int end,string s){
        while(start<=end){
            if(s[start++]!=s[end--])return false;
        }
        return true;
    }
    void solution(int idx, string s,vector<string>& subStr, vector<vector<string>>& ans){
        if(idx==s.size()){
            ans.push_back(subStr);
            return;
        }
        for(int i=idx;i<s.size();++i){
            if(isPalindrome(idx,i,s)){
                subStr.push_back(s.substr(idx,i-idx+1));
                solution(i+1,s,subStr,ans);
                subStr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> subStr;
        solution(0,s,subStr,ans);
        return ans;

    }
};