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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode*slow=head;
        ListNode*first=head;

        while(first!=NULL &&first->next!=NULL){
            slow=slow->next;
            first=first->next->next;
        }

        ListNode*curr=slow;
        ListNode*prev=NULL;

        while(curr!=NULL){
            ListNode*temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        
        while(prev!=NULL ){
            if(head->val!=prev->val) return false;
            head=head->next;
            prev=prev->next;
        }
        return true;

    }
};