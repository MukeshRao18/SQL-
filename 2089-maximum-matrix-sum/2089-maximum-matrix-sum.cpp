class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        long long sum=0,c=0;
        int minASum=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=abs(matrix[i][j]);
                if(matrix[i][j]<0){
                    c++;
                }
                minASum=min(minASum,abs(matrix[i][j]));
            }
        }
        if(c%2==0){
            return sum;
        }
        return sum-2*minASum;
    }
};