class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)return 1;
        if(x==0)return 0; 
        if(n<0){
            x=1/x;
        }
        double ans=1;
        long num=labs(n);
        while(num){
            if(num&1){
                ans=ans*x;
            }
            x=x*x;
            num>>=1;
        }
        return ans;
        
    }
};