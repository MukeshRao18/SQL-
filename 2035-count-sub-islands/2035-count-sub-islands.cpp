class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int res=0;
        for(int i=0;i<grid2.size();i++){
            for(int j=0;j<grid2[0].size();j++){
                    if(grid2[i][j]==1 && solve(grid1,grid2,i,j)){
                        res++;
                    }
            }
        }
        return res;
    }
    bool solve(vector<vector<int>>& grid1,vector<vector<int>>& grid2,int i,int j){
        if(i<0||j<0||i>=grid2.size()||j>=grid2[0].size()||grid2[i][j]!=1){
            return true;
        }
        grid2[i][j]=-1;
        bool result=grid1[i][j]==1;

        result= result & solve(grid1,grid2,i+1,j);
         result= result & solve(grid1,grid2,i-1,j);
          result= result & solve(grid1,grid2,i,j+1);
           result= result & solve(grid1,grid2,i,j-1);

           return result;
    }
};