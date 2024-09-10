class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int l=0,r=c.size()-1,sum=0;
        for(int i=0;i<k;i++){
            sum+=c[i];
        }
        int maxi=0;
        maxi=max(maxi,sum);
        for(int i=k-1;i>=0;i--){
            sum-=c[i];
            sum+=c[r];
            maxi=max(maxi,sum);
            r--;
        }
        return maxi;
    }
};