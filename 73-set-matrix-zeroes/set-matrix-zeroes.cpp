class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRowHasZero=false;
        bool firstColHasZero=false;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            if(matrix[i][0]==0) firstColHasZero=true;
        }
        for(int j=0;j<m;j++){
            if(matrix[0][j]==0) firstRowHasZero=true;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]!=0){
                    if(matrix[i][0]==0 || matrix[0][j]==0)matrix[i][j]=0;
                }
            }
        }
        if(firstRowHasZero){for(int i=0;i<m;i++)matrix[0][i]=0;}
        if(firstColHasZero){for(int i=0;i<n;i++)matrix[i][0]=0;}
    }
};