class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res=(start^goal);
        return __builtin_popcount(res);
    }
};