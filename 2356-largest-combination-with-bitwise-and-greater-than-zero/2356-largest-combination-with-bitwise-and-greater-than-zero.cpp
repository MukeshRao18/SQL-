class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int result=0;
        for(int i=0;i<24;i++){
            int c=0;
            for(int a:candidates){
                if(a&(1<<i))
                    c++;
            }
            result=max(result,c);
        }
        return result;
    }

};