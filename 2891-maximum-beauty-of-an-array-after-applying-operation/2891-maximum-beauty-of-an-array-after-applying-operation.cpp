class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=0,ans=0;
        while(j<n){
            if(nums[j]-nums[i]<=2*k){
             ans=max(ans,j-i+1);
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};