class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int maxArea=0, width=0,area=0;
        while(left<right){
            width=abs(right-left);
            area=min(height[left],height[right])*width;
            maxArea=max(area,maxArea);
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxArea;
    }
};