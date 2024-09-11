class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int o=image[sr][sc];
        vis[sr][sc]=o;
      
        queue<pair<int,int>> q;
        q.push({sr,sc});
 
        int dr[4]={-1,0,1,0};
         int dc[4]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            image[r][c]=color;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nc>=0&&nr>=0&&nr<n&&nc<m&&image[nr][nc]==o&&!vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }

        }
        return image;
    }
};