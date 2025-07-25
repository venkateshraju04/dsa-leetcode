class Solution {
public:
    bool isPalindrome(string s) {
        int start=0;
        int end=s.length()-1;
        while(start<=end){
            char currStart = s[start];
            char currEnd = s[end];
            if(!isalnum(currStart)){
                start++;
            }
            else if(!isalnum(currEnd)){
                end--;
            }
            else
            {
                if(tolower(currStart)!=tolower(currEnd)){
                    return false;
                }
                start++;
                end--;
            }
        }
        return true;
    }
};