class Solution {
public:
    bool find(int x,vector<int> &q,int n){
        for(int product:q){
            n-=(product+x-1)/x;
            if(n<0){
                return false;
            }
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m=quantities.size(),maxi=0;
        for(int i=0;i<m;i++){
         maxi=max(maxi,quantities[i]);
        }
        int l=1,r=maxi;
        int result=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(find(mid,quantities,n)){
                result=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return result;
    }
};