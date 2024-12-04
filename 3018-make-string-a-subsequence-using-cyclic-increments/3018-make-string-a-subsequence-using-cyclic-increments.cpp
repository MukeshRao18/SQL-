class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        if(n<m) return false;
        int cnt=0;
        int j=0;
        for(int i=0;i<n;i++){
            if(str1[i]==str2[j]||str1[i]=='z'&&str2[j]=='a') {
               cnt++;
                j++;
                continue;
            }
            int a=str1[i]-'a';
            int b=str2[j]-'a';
            if(a<b&&abs(b-a)<=1){
                cnt++;
                j++;
            }
        }
        if(cnt==m) return true;
        return false;
    }
};