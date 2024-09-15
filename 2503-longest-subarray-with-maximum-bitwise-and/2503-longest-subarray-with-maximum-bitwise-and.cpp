class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=max_element(nums.begin(),nums.end())-nums.begin();
        int cnt=0,x=nums[maxi];
        for(int i=maxi;i<nums.size();i++){
            int len=0;
            while(i<nums.size() && nums[i]==x){
                len++;
                i++;
            }
            cnt=max(cnt,len);
        }
        return cnt;
    
    }
};