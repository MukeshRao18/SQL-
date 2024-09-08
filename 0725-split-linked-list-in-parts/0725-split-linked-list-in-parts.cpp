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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        int size=cnt/k;
        int rem=cnt%k;
        ListNode* temp1=head;
        vector<ListNode*> res(k,nullptr);
        for(int i=0;i<k&&temp1!=NULL;i++){
               res[i]=temp1;
               int currsize=size+(rem>0?1:0);
               rem--;
               for(int i=1;i<currsize;i++){
                   temp1=temp1->next;
               }
            ListNode* s=temp1->next;
            temp1->next=NULL;
            temp1=s;
        }
        return res;
    }
};