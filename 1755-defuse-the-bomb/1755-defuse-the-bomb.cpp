class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int> ans(code.size(),0);
        if(k==0) return ans;
        int start=0,end=0;
        if(k>0){
            start=1;
            end=k;
        }
        else {
            start=n-abs(k);
            end=n-1;
        }
        int sum=0;
        for(int i=start;i<=end;i++){
            sum+=code[i];
        }
        for(int i=0;i<n;i++){
            ans[i]=sum;
            sum-=code[(start)%n];
            sum+=code[(end+1)%n];
            start++;
            end++;
        }
        return ans;
    }
};