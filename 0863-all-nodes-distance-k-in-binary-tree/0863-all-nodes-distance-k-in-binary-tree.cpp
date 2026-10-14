/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int>result;
    map<TreeNode*,TreeNode*>m;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
    auto node=q.front();
    q.pop();
    if(node->left){ m[node->left]=node;
    q.push(node->left);
    }
    if(node->right){ 
    q.push(node->right);    
    m[node->right]=node;}
    }

    queue<pair<TreeNode*,pair<TreeNode*,int>>>pq;
    pq.push({target,{NULL,0}});
    while(!pq.empty()){
    auto [node,para]=pq.front();
    auto parent=para.first;
    auto distance=para.second;
    pq.pop();
    if(distance==k){
    result.push_back(node->val);
    continue;    
    }
    if(node->left!=NULL && node->left!=parent) pq.push({node->left,{node,distance+1}});
    if(node->right!=NULL && node->right!=parent) pq.push({node->right,{node,distance+1}});
    if(m.find(node)!=m.end() && m[node]!=parent) pq.push({m[node],{node,distance+1}});    
    }
    return result;
    }
};