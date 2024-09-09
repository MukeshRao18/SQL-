class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0,right=0,maxi=0,zeros=0;
        while(right<nums.size()){
            if(nums[right]==0){
               zeros++;
            }
            while(zeros>k){
                if(nums[left]==0){
                    zeros--;
                }
                left++;
            }
            maxi=max(maxi,right-left+1);
            right++;
        }
        return maxi;
    }
};