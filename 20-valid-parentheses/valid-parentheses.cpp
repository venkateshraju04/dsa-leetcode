class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char>mp{
            {')', '('},
            {']','['},
            {'}','{'}
        };
        stack<char> Stack;
        for(int i=0;i<s.length();i++){
            if(mp.count(s[i])==0){
                Stack.push(s[i]);
            }
            else{
                if(Stack.empty() || Stack.top()!=mp[s[i]])
                return false;
                Stack.pop();
            }
        }
        return Stack.empty();
    }
};