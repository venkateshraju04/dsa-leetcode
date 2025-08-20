class Solution {
public:
    string decodeString(string s) {
        stack<int>numStack;
        stack<string>stringStack;
        string ans="";
        int num=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                num=num*10 + (s[i]-'0');
            }
            else if (s[i]=='['){
                numStack.push(num);
                stringStack.push(ans);
                num=0;
                ans="";
            }else if(s[i]==']'){
                int repeat=numStack.top(); numStack.pop();
                string str=stringStack.top(); stringStack.pop();
                string temp="";
                for(int j=0;j<repeat;j++){temp+=ans;}
                ans=str+temp;
            }else{
                ans+=s[i];
            }
        }
        return ans;
    }
};