class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        vector<vector<int>> dp(n,vector<int>(m,0)); 
                for (int i = 0; i < m; i++) {  // Fixing row/col indexing in the first row
            dp[0][i] = matrix[0][i];
            ans += matrix[0][i];
        }
        for (int i = 1; i < n; i++) {  // Fixing row/col indexing in the first column
            dp[i][0] = matrix[i][0];
            ans += matrix[i][0];
        }


        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                  if(matrix[i][j]==1){
                       dp[i][j]=1+min({dp[i][j-1],dp[i-1][j-1],dp[i-1][j]});
                  }
                  ans+=dp[i][j];
            }
        }
        return ans;
    }
};