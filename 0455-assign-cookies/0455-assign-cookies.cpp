class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size(),m=s.size();
        int cnt=0;
        int i=0,j=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(i<n&&j<m){
            if(g[i]<=s[j]) { 
                cnt++;
                i++;j++;
            }
            else{
                j++;
            }
        }
        return cnt;
    }
};