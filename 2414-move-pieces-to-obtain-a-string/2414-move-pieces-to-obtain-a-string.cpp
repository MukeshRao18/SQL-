class Solution {
public:
    bool canChange(string start, string target) {
        int n=start.size();
       // unordered_map<string,bool> mp;
       int i=0,j=0;
       while(i<n||j<n){
        while(i<n&&start[i]=='_') i++;
        while(j<n&&target[j]=='_') j++;
        if(i==n||j==n){
            return i==n && j==n;
        }
        if(start[i]!=target[j]) return false;
        if(start[i]=='L'&&i<j) return false;
        if(start[i]=='R'&&i>j) return false;
        i++;j++;
        cout<<i<<j<<" ";
       }
        //return solve(start,target,n,mp);
        return true;
    }
    bool solve(string &s,string &t,int n,unordered_map<string, bool> &mp){
        if(s==t){
            return true;
        }
        if(mp.count(s)){
            return mp[s];
        }
        for(int i=0;i<n;i++){
            if(s[i]=='L'&&i>0&&s[i-1]=='_'){
                 swap(s[i],s[i-1]);
                 cout<<s<<":";
                 if(solve(s,t,n,mp)==true){
                    return true;
                 }
                 swap(s[i],s[i-1]);
            }
            else if(s[i]=='R'&&i<n-1&&s[i+1]=='_'){
                   swap(s[i],s[i+1]);
                   cout<<s<<"::";
                 if(solve(s,t,n,mp)==true){
                    return true;
                 }
                 swap(s[i],s[i+1]);
            }
        }
        return mp[s]=false;
    }
};