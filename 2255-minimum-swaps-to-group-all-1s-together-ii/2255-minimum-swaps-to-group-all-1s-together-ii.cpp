class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int ones=accumulate(nums.begin(),nums.end(),0);
        int curr=accumulate(nums.begin(),nums.begin()+ones,0);
         int maxi=curr;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) curr--;
            if(nums[(ones+i)%nums.size()]==1) curr++;
            maxi=max(maxi,curr);
        } 
        return ones-maxi;
    }
};