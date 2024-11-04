class Solution {
public:
    string compressedString(string word) {
        int c=0;
        string res="";
        char prev=word[0];
        for(int i=0;i<word.size();i++){
            if(c<9&&word[i]==prev){
                c++;
            }
            else{
               res.push_back(c+'0');
               res.push_back(prev);
               c=1;
               prev=word[i];
            }
        }
        res.push_back(c+'0');
        res.push_back(prev);
        return res;
    }
};