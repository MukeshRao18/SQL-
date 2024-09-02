class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        long int sum=0;
        for(int i = 0; i < n; i++){
             sum += chalk[i];
        }
        int ans=0;
        int remaining = k % sum;
        for(int i=0;i<n;i++){
            if(remaining < chalk[i]){
                return i;
            }
            remaining -= chalk[i];

        }
        return 0;
    }
};