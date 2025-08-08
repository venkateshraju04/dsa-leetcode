class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas=0;
        int curr=0;
        int n=gas.size();
        int startIdx=0;
        for(int i=0;i<n;i++){
            total_gas+=gas[i]-cost[i];
            curr+=gas[i]-cost[i];
            if(curr<0){
                curr=0;
                startIdx=i+1;
            }
        }
        if(total_gas<0)return -1;
        return startIdx;
    }
};