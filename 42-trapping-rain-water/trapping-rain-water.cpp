class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> prefix(n),suffix(n);
        int prefixMax=INT_MIN, suffixMax=INT_MIN;
        for(int i=0;i<n;i++){
            prefixMax=max(prefixMax,height[i]);
            prefix[i]=prefixMax;
        }
        for(int i=n-1;i>=0;i--){
            suffixMax=max(suffixMax,height[i]);
            suffix[i]=suffixMax;
        }
        int maxWater=0;
        for(int i=0;i<n;i++){
            maxWater+=min(prefix[i],suffix[i])-height[i];
        }
        return maxWater;
    }
};