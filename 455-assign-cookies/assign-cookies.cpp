class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int sIdx=0;
        int gIdx=0;
        while(sIdx<s.size() && gIdx<g.size()){
            if(s[sIdx]>=g[gIdx]){
                gIdx++;
            }
            sIdx++;
        }
        return gIdx;
    }
};