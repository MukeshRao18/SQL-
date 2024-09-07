class Solution {
public:
bool static comp(const vector<int>&a,const vector<int>&b){
    return a[1]<b[1];
}
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        int n=nums.size(),cnt=1;
        sort(nums.begin(),nums.end(),comp);
        int freet=nums[0][1];
        for(int i=1;i<n;i++){
            if(nums[i][0]>=freet){
                 cnt++;
                 freet=nums[i][1];
            }
        }
    return abs(cnt-n);
    }
};