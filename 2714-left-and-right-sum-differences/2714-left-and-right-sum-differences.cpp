class Solution {
public:
    int sum(int left,int right,int i,vector<int> &nums){
        for(int j=i-1;j>=0;j--){
            left=left+nums[j];
        }
        for(int j=i+1;j<nums.size();j++){
            right=right+nums[j];
        }
        return abs(left-right);
    }
    vector<int> leftRightDifference(vector<int>& nums) {
        int left=0,right=0;
        vector<int> res; 
        for(int i=0;i<nums.size();i++){
            int a=sum(left,right,i,nums);
            res.push_back(a);
        }
        return res;
    }
};