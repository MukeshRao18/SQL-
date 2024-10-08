/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if(root==NULL) return {};
        vector<int> arr;
        solve(root,arr);
        arr.push_back(root->val);
        return arr;
    }
    void solve(Node * &root, vector<int> &arr){
        if(root==NULL){
               return;
        }
        for(auto child : root->children){
            solve(child,arr);
            arr.push_back(child->val);
        } 
        
    }
};