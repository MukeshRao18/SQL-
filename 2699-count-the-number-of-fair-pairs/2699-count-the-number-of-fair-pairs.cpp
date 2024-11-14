class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long ans=0;
        for(int i=0;i<n;i++){
            int low=lower-nums[i];
            int up=upper-nums[i];
            ans+=find(nums,i+1,n-1,up+1)-find(nums,i+1,n-1,low);
        }
        return ans;
    }
    int find(vector<int> &nums,int l,int r,int target){
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]>=target) r=m-1;
            else l=m+1;
        }
        return r;
    }
};