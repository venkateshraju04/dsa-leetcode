class Solution {
public:
    int smallestNumber(int n) {
        int num=log2(n)+1;
        int ans=(1<<num)-1;
        return ans;
    }
};