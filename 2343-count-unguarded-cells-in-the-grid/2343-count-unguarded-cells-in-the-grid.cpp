class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(auto i:walls){
            vis[i[0]][i[1]]=3;
        }
        for(auto i:guards){
          vis[i[0]][i[1]]=2;
        }
        for(auto i:guards){
            solve(i[0],i[1],vis,m,n);
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0) ans++;
            }
            cout<<endl;
        }
        return ans;
    }
    void solve(int i,int j,vector<vector<int>> &vis,int m,int n){
        for(int k=i+1;k<m;k++){
            if(vis[k][j]==2||vis[k][j]==3) break;
            vis[k][j]=1;
        }
        for(int k=j+1;k<n;k++){
            if(vis[i][k]==2||vis[i][k]==3) break;
            vis[i][k]=1;
        }
        for(int k=i-1;k>=0;k--){
            if(vis[k][j]==2||vis[k][j]==3) break;
            vis[k][j]=1;
        }
        for(int k=j-1;k>=0;k--){
            if(vis[i][k]==2||vis[i][k]==3) break;
            vis[i][k]=1;
        }
    }
};