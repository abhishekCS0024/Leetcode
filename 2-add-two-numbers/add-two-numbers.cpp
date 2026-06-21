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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // if(head==NULL)  return head;

        
        ListNode*head=new ListNode(0);
        ListNode*curr=head;
        int rem=0;
        while(l1!=NULL && l2!=NULL){
            int temp=(l1->val)+(l2->val)+rem;
            
            if(temp>9){
                rem=temp/10;
                temp=temp%10;                
            }
            else{
                rem=0;
            }

            ListNode*node=new ListNode(temp);
            curr->next=node;  
            curr=node; 
            l1=l1->next; l2=l2->next;         
        }
        if(l1!=NULL){
            while(l1!=NULL){
                int temp=(l1->val)+rem;
                if(temp>9){
                    rem=temp/10;
                    temp=temp%10;                
                }
                else{
                    rem=0;
                }
                ListNode*node=new ListNode(temp);
                curr->next=node;  
                curr=node; 
                l1=l1->next;
            }
        }
        if(l2!=NULL){
            while(l2!=NULL){
                int temp=(l2->val)+rem;
                if(temp>9){
                    rem=temp/10;
                    temp=temp%10;                
                }
                else{
                    rem=0;
                }
                ListNode*node=new ListNode(temp);
                curr->next=node;  
                curr=node; 
                l2=l2->next;
            }
        }
        if(rem!=0){
            ListNode*node=new ListNode(rem);
            curr->next=node;
        }
        return head->next;
    }
};