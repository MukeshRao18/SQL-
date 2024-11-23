class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> mpp;
        int m=matrix[0].size();
        for(auto a:matrix){
            string s="";
            for(int i=0;i<m;i++){
                if(a[i]==a[0]){
                    s+="s";
                }
                else{
                    s+="b";
                }
            }
            mpp[s]++;
        }
        int maxi=INT_MIN;
        for(auto a:mpp){
            maxi=max(maxi,a.second);
        }
        return maxi;
    }
};