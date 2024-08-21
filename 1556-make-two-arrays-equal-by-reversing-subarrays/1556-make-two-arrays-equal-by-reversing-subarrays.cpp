class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(int i=0;i<arr.size();i++){
            mpp[target[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            if(mpp.find(arr[i])!=mpp.end()){
                mpp[arr[i]]--;
                if(mpp[arr[i]]==0)
                mpp.erase(arr[i]);
            }
        }
        return mpp.size()==0;
    }
};