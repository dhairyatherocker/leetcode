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
    void dfs(TreeNode* &node,TreeNode* &prev_node,int dis,map<TreeNode*,TreeNode*>&m,vector<int>&ans ){
    if(dis==0){ans.push_back(node->val);
    return;
    }
    if(node->left!=NULL && prev_node!=node->left) dfs(node->left,node,dis-1,m,ans);
    if(node->right!=NULL && prev_node!=node->right) dfs(node->right,node,dis-1,m,ans);
    if(m.find(node)!=m.end() && m[node]!=prev_node) dfs(m[node],node,dis-1,m,ans);
    return;    
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    map<TreeNode*,TreeNode*>m;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
    auto node=q.front();
    q.pop();
    if(target->val==node->val) target=node;
    if(node->left!=NULL){
    m[node->left]=node;
    q.push(node->left);     
    }
    if(node->right!=NULL){
    m[node->right]=node;
    q.push(node->right);    
    }    
    }
    vector<int>ans;
    dfs(target,target,k,m,ans);
    return ans;

    }
};