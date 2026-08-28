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
    stack<ListNode*>st;
    ListNode* dummy=head;
    while(dummy!=NULL){
        st.push(dummy);
        dummy=dummy->next;
    }
    dummy=head;
    while(dummy!=NULL){
    auto node=st.top();
    if(node->val!=dummy->val) return false;
    dummy=dummy->next;
    st.pop();     
    } 
    return true;   
    }
};