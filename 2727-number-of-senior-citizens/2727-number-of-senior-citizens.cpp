#include<string>
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(int i=0;i<details.size();i++){
            int num=stoi(details[i].substr(11,2));
            if(num>60){
                ans++;
            }
        }
        return ans;
    }
};