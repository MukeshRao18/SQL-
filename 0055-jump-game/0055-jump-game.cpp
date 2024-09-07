class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> memo(nums.size(), -1); 
        
        return solve(nums, 0, nums.size() - 1, memo);
    }
    
    bool solve(vector<int>& nums, int idx, int n, vector<int>& memo) {
        if (idx >= n) {
            return true;
        }
        
        
        if (memo[idx] != -1) {
            return memo[idx];
        }
        
        if (nums[idx]) {
            for (int i = 1; i <= nums[idx]; i++) {
                if (solve(nums, idx + i, n, memo)) {
                    return memo[idx] = true; 
                }
            }
        } 
        
        return memo[idx] = false; 
    }
};
