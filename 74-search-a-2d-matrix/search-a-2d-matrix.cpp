class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int nrow=matrix.size(), ncol=matrix[0].size();
        int right=ncol-1, left=0;
        while(left<nrow && right>-1){
            if(matrix[left][right]==target)return true;
            else if(matrix[left][right]<target){
                left++;
            }else{
                right--;
            }
        }
        return false;
    }
};