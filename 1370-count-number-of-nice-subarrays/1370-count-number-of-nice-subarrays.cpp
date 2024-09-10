class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       int l=solve(nums,k);
       int r=solve(nums,k-1);
       return abs(l-r);
    }
    int solve(vector<int> &nums,int k){
        if(k<0) return 0;
         int l=0,r=0,cnt=0,maxi=0;

        while(r<nums.size()){
            cnt+=nums[r]%2;

            while(cnt>k){
                if(nums[l]%2==1) cnt--;
                l++;
            }
            maxi=maxi+(r-l+1);
            r++;
        }
        return maxi;
    }
};