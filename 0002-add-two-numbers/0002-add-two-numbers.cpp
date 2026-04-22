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
    ListNode* dummy=new ListNode(-1);
    ListNode* head=dummy;
    int carry=0;
    ListNode* temp_1=l1;
    ListNode* temp_2=l2;
    while(temp_1!=NULL && temp_2!=NULL){
    int sum=temp_1->val+temp_2->val+carry;
    ListNode* temp=new ListNode(sum%10);
    carry=sum/10;
    head->next=temp;
    head=temp;
    temp_1=temp_1->next;
    temp_2=temp_2->next;     
    }
    while(temp_1!=NULL){
    int sum=temp_1->val+carry;
    ListNode* temp=new ListNode(sum%10);
    carry=sum/10;
    head->next=temp;
    head=temp;
    temp_1=temp_1->next;    
    }
    while(temp_2!=NULL){
    int sum=temp_2->val+carry;
    ListNode* temp=new ListNode(sum%10);
    carry=sum/10;
    head->next=temp;
    head=temp;
    temp_2=temp_2->next;     
    }
    if(carry!=0){
     ListNode* temp=new ListNode(carry);
     head->next=temp;
    }
  return dummy->next;
    }
};