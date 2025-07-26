class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        int f=0;
        int count=0;
        int size=tasks.size();
        for(auto task: tasks){
            mp[task]++;
            if(f<mp[task]) f=mp[task];
        }

        for(auto it: mp){
            if(it.second==f){
                count++;
            }
        }
        return max((n+1)*(f-1)+count, size);
    }
};