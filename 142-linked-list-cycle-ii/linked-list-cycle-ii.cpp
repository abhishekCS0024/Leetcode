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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;

        ListNode*slow=head;
        ListNode*fast=head;

        while(slow!=NULL && fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                
                ListNode*curr=slow->next;
                slow->next=NULL;

                unordered_set<ListNode*>mp;

                while(head!=NULL){
                    mp.insert(head);
                    head=head->next;
                }

                while(curr!=NULL){
                    if(mp.count(curr)){
                        return curr;
                    }
                    curr=curr->next;
                }


            }

            
        }

        return NULL;
    }
};