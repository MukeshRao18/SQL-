class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        int n=s.size(),j=0,maxi=INT_MIN;
        if(n==0) return 0;
        for(int i=0;i<n;i++){
            if(mpp.find(s[i])!=mpp.end()&&mpp[s[i]] >= j){
                j=mpp[s[i]]+1;
            }
            mpp[s[i]]=i;
            maxi=max(maxi,i-j+1);
        }
        return maxi;
    }
};