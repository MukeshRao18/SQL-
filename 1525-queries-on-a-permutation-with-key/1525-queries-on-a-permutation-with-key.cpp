class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int n=queries.size();
        vector<int> pro;
        for(int i=1;i<=m;i++){
            pro.push_back(i);
        }
        vector<int> res;
        for(int i=0;i<queries.size();i++){
             int ele=queries[i];
             auto a=find(pro.begin(),pro.end(),ele);
             int length;
             if(a!=pro.end()){
                length=distance(pro.begin(),a);
             }
             res.push_back(length);
             pro.erase(pro.begin()+length);
             pro.insert(pro.begin(),ele);
        }
        return res;
    }
};