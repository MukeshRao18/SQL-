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
class Solution {
public:
    ListNode * temp;
    bool ispalindrome(ListNode* curr){
        if(curr==NULL) return true;
        bool pal=ispalindrome(curr->next)&&(temp->val==curr->val);
        temp=temp->next;
        return pal;
    }
    bool isPalindrome(ListNode* head) {
        temp=head;
        return ispalindrome(head);
    }
};