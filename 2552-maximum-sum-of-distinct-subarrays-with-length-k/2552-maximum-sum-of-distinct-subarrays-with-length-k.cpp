class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long  l,r,sum=0,ans=0;
        l=0;
        r=0;
        unordered_set<int> s;

        while(r<n){
            while(s.count(nums[r])){
                sum-=nums[l];
                s.erase(nums[l]);
                l++;
            }    
            sum+=nums[r];
            s.insert(nums[r]);
            if(r-l+1==k){
                ans=max(ans,sum);
                sum-=nums[l];
                s.erase(nums[l]);
                l++;
            }
            r++;
        }
        return ans;
    }
};