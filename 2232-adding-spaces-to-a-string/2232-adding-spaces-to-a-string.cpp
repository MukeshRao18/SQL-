class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int j=0;
        vector<char> ans;
        for(int i=0;i<s.size();i++){
            if(j<spaces.size()&&i==spaces[j]){
                ans.push_back(' ');
                j++;
            }
            ans.push_back(s[i]);
        }
        string res="";
        for(int i=0;i<ans.size();i++){
                     res+=ans[i];
        }
        return res;
    }
};