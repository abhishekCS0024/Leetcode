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
    ListNode* sortList(ListNode* head) {
        vector<int>temp;

        ListNode*curr=head;

        while(curr){
            temp.push_back(curr->val);
            curr=curr->next;
        }
        sort(temp.begin(),temp.end());
        ListNode*head2=new ListNode(0);
        curr=head2;
        for(int i=0;i<temp.size();i++){
            ListNode*node=new ListNode(temp[i]);
            curr->next=node;
            curr=node;
        }

        return head2->next;
    }
};