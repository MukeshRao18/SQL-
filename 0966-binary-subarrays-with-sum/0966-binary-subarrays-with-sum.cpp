class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int g=solve(nums,goal);
        int g1=solve(nums,goal-1);
        return abs(g-g1);
    }
    int solve(vector<int> & nums,int goal){
        int l=0,r=0,sum=0,cnt=0;
        if(goal<0) return 0;
        while(r<nums.size()){
            sum+=nums[r];

            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            cnt= cnt + (r-l+1);
            r++;
        }
        return cnt;
    }
};