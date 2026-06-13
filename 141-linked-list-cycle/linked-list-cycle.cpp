/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return false;
        ListNode*curr1=head;
        ListNode*curr2=head;

        while(curr1->next!=NULL && curr2->next->next!=NULL){
            
            curr1=curr1->next;

            curr2=curr2->next->next;

            if(curr2->next==NULL) return false;
            if(curr1==curr2) return true;
        }

        return false;
    }
};