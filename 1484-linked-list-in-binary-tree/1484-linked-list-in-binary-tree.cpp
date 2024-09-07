/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
bool valid=false;
    bool isSubPath(ListNode* head, TreeNode* root) {
        string a="";
        ListNode* temp=head;
        while(temp!=NULL){
            int s=temp->val;
            a+=to_string(s);
            temp=temp->next;
        }
        solve(root,"",a);
       return valid;
    }
    void solve(TreeNode* root,string curr,string& a){
        if(root==NULL){
            return;
        }
        curr+=to_string(root->val);
        if(curr.find(a)!=string::npos){
                 valid=true;
                 return;
        }
        solve(root->left,curr,a);
        solve(root->right,curr,a);
        curr.pop_back();
    }
};