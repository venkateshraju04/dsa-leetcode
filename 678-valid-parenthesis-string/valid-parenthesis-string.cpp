class Solution {
public:
    bool checkValidString(string s) {
        int minCount=0, maxCount=0;
        for(char c:s ){
            if(c=='('){
                minCount++;
                maxCount++;
            }else if(c==')'){
                minCount--;
                maxCount--;
            }else{
                minCount--;
                maxCount++;
            }
            if(minCount<0) minCount=0;
            if(maxCount<0)return false;
        }
        return minCount==0;
    }
};