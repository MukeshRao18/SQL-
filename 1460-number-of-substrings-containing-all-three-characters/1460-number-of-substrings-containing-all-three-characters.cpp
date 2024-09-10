class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt=0;
        vector<int> arr(3,-1);
        for(int i=0;i<s.size();i++){
              arr[s[i]-'a']=i;
              int a=min(arr[0],arr[1]);
              cnt=cnt+1+min(a,arr[2]);
        }
        return cnt;
    }
};