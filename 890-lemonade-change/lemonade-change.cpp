class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveUSD=0, tenUSD=0;
        for(int bill:bills){
            if(bill==5){
                fiveUSD++;
            }else if(bill==10){
                if(fiveUSD){
                    tenUSD++;
                    fiveUSD--;
                }else{
                    return false;
                }
            }else{
                if(fiveUSD>0 && tenUSD>0){
                    fiveUSD--;
                    tenUSD--;
                }
                else if(fiveUSD>2){
                    fiveUSD-=3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};