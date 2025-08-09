class Solution {
public:
    bool isValid(string s) {
       unordered_map<char,char>map={
        {')','('}, {']','['},{'}','{'}
       };
       stack<char> Stack;
       for(char c:s){
        if(map.count(c)==0){
            Stack.push(c);
        }else{
            if(Stack.empty() || Stack.top()!=map[c])return false;
            Stack.pop();
        }
       }
       return Stack.empty();
    }
};