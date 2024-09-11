class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size(),cnt=0;
        vector<vector<int>> adjLs(v);
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(i!=j&& isConnected[i][j]==1){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        vector<int> vis(v, 0);
        for(int i=0;i<v;i++){
            if(vis[i]==0){
                dfs(i,vis,adjLs);
                cnt++;
            }
        }
        return cnt;
    }
    void dfs(int i,vector<int>& vis,vector<vector<int>> &adjLs){
        vis[i]=1;
        for(int it:adjLs[i]){
            if(!vis[it]){
                dfs(it,vis,adjLs);
            }
        }
    }
};