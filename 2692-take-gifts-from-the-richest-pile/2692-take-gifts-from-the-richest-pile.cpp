class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> p(gifts.begin(),gifts.end());
        long long sum=0;
        for(int g:gifts){
         sum+=g;
        }

        while(k--){
            int maxi=p.top();
            p.pop();
            int rem=sqrt(maxi);
            sum-=(maxi-rem);
            p.push(rem);
        }
        return sum;
    }
};