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
    ListNode* reverseList(ListNode* head) {
     if(head==NULL) return NULL;   
    ListNode* left=NULL;
    ListNode* right=head->next;
    ListNode* mover=head;
    while(mover->next!=NULL){
    mover->next=left;
    left=mover;
    mover=right;
    right=right->next;    
    }
    mover->next=left;
    return mover;    
    }
};