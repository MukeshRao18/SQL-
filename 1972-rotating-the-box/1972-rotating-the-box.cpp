class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size();
        int m=box[0].size();
        vector<vector<char>> ans(m,vector<char>(n,'.'));
        for(int i=0;i<n;i++){
            int k=m-1;
            int k1=m-1;
            int x=n-i-1;
            for(int j=m-1;j>=0;j--){
                if(box[i][j]=='*'){
                    ans[k1][x]='*';
                    k=j-1;
                }
                if(box[i][j]=='#'){
                    ans[k][x]='#';
                    k--;
                }
                k1--;
            }
        }
        return ans;
    }
};