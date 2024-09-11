class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));  
        int fresh = 0;  
        queue<pair<pair<int, int>, int>> q;

    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    vis[i][j] = 2;
                    q.push({{i, j}, 0});  
                } else if (grid[i][j] == 1) {
                    fresh++;  
                }
            }
        }

        int cnt = 0;  
        int dr[4] = {-1, 0, 1, 0};  
        int dc[4] = {0, 1, 0, -1}; 
        int tm = 0;  

      
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();

            tm = max(tm, t);  

       
            for (int i = 0; i < 4; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];


                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0) {
                    vis[nrow][ncol] = 2;  
                    q.push({{nrow, ncol}, t + 1});  
                    cnt++;  
                }
            }
        }

        
        if (fresh != cnt) return -1;

       
        return tm;
    }
};
