class Solution {
public:
    int maximumSwap(int num) {
        vector<int> arr;
        int mini=INT_MAX,maxi=INT_MIN;
        while(num>0){
            int rem=num%10;
            mini=min(mini,rem);
            maxi=max(maxi,rem);
            arr.push_back(rem);
            num=num/10;
        }
        string s="";
        for(int i:arr){
            s=to_string(i)+s;
        }
        sort(arr.begin(),arr.end());
        string ss="";
        for(int i:arr){
            ss=to_string(i)+ss;
        }
        cout<<ss;
        for(int i=0;i<arr.size();i++){
            if(s[i]!=ss[i]){
                int ind = s.rfind(ss[i], s.size() - 1);
                swap(s[i], s[ind]);
                break;
            }
        }
        int m=stoi(s);
        return m;
    }
};