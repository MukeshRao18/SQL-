class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum=0;
        for(int i=0;i<rolls.size();i++){
            sum+=rolls[i];
        }
        int tar=mean*(rolls.size()+n)-sum;
        if(tar>6*n||tar<n) return {};
        vector<int> res;
        int div=n;
        while(tar>0){
            int num=tar/div;
            res.push_back(num);
            tar=tar-num;
            div--;
        }
        return res;
    }
};