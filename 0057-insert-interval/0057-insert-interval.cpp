class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newinterval) {
        int i=0,n=intervals.size();
        vector<vector<int>> res;
        while(i<n){
           while(i<n&&intervals[i][1]<newinterval[0]){
            res.push_back(intervals[i]);
            i++;
           }
           while(i<n&& intervals[i][0]<=newinterval[1]){
            newinterval[0]=min(intervals[i][0],newinterval[0]);
            newinterval[1]=max(intervals[i][1],newinterval[1]);
            i++;
           }
           res.push_back({newinterval[0],newinterval[1]});
           while(i<n){
            res.push_back(intervals[i]);
            i++;
           }
        }
        if(n==0){
            res.push_back({newinterval[0],newinterval[1]});
        }
        return res;
    }
};