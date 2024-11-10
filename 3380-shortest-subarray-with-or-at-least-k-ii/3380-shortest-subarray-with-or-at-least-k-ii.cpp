class Solution {
public:
    void update(vector<int> &vec,int value,int num){
        for(int i=0;i<32;i++){
            if((num>>i)&1){
                vec[i]+=value;
            }
        }
    }
    int getValue(vector<int> &vec){
        int ans=0;
        for(int i=0;i<vec.size();i++){
            if(vec[i]>0){
                 ans|=(1<<i);
            }
        }
        return ans;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int result=INT_MAX;
        int n=nums.size();
        vector<int> vec(32,0);
        int i=0,j=0;
        while(j<n){
            update(vec,1,nums[j]);
            while(i<=j&&getValue(vec)>=k){
                result=min(result,j-i+1);
                update(vec,-1,nums[i]);
                i++;
            }
            j++;
        }

    return result==INT_MAX?-1:result;
    }
};