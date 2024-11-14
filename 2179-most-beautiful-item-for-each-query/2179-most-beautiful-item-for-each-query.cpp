class Solution {
public:
    int binary(vector<vector<int>> &items,int query){
        int l=0,r=items.size()-1;
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(items[mid][0]>query){
                r=mid-1;
            }
            else{
              ans=max(ans,items[mid][1]);
              l=mid+1;
            }
        }
        return ans;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        int n=items.size(),m=queries.size();
        int maxi=items[0][1];
        for(int i=1;i<n;i++){
            maxi=max(maxi,items[i][1]);
            items[i][1]=maxi;
        }

        vector<int> result(m);
        for(int i=0;i<m;i++){
            result[i]=binary(items,queries[i]);
        }
      return result;
    }
};