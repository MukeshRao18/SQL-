class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       
        vector<int> originalArr = arr;

  
        sort(arr.begin(), arr.end());

       
        unordered_map<int, int> mpp;
        int rank = 1;

        for(int i = 0; i < arr.size(); i++) {
         
            if(i == 0 || arr[i] != arr[i - 1]) {
                mpp[arr[i]] = rank++;
            }
        }

        
        for(int i = 0; i < originalArr.size(); i++) {
            originalArr[i] = mpp[originalArr[i]];
        }

        return originalArr;
    }
};
