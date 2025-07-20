class Solution {
public:
    int divide(int dividend, int divisor) {
        int flag=1;
        if(dividend<0 && divisor>0) flag=-1;
        if(dividend>0 && divisor<0) flag=-1;

        if(dividend==0)return 0;
        if(dividend==divisor)return 1;

        long ans=0;

        long n = abs((long)dividend);
        long d=abs((long)divisor);
        while(n>=d){
            int count=0;
            while(n>=(d<<(count+1))){
                count++;
            }
            ans+=(1<<count);
            n-=(d<<count);
        }
        if(ans==(1<<31) && flag==1)return INT_MAX;
        if(ans==(1<<31) && flag==-1)return INT_MIN;

        return flag==1?ans:-ans;
    }
};