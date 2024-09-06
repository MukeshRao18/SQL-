class Solution {
public:
    bool checkValidString(string s) {
        int mini=0,maxi=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                mini++;
                maxi++;
            }
            else if(s[i]==')'){
                mini=max(mini-1,0);
                maxi--;
            }
            else if(s[i]=='*'){
                maxi++;
                mini=max(mini-1,0);
            }
            if(maxi<0) return false;
        }
        return mini==0;
    }
};