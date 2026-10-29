/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
    Node* dummy=new Node(-1);
    Node* head_copy=dummy;
    Node* temp=head;
    map<Node*,Node*>m;
    while(temp!=NULL){
    Node* temp_node=new Node(temp->val);
    head_copy->next=temp_node;
    m[temp]=temp_node;
    temp=temp->next;
    head_copy=head_copy->next;
    }
    head_copy=dummy->next;
    temp=head;
    while(temp!=NULL){
    if(temp->random!=NULL){
    Node* random_node=temp->random;
    head_copy->random=m[random_node];    
    }
    head_copy=head_copy->next;
    temp=temp->next;    
    }
    return dummy->next;    
    }
};