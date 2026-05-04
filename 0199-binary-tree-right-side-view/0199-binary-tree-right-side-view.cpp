/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
    map<int,int>m;
    queue<pair<TreeNode*,int>>q;
    if(root==NULL) return {};
    q.push({root,0});
    while(!q.empty()){
    auto [node,level]=q.front();
    q.pop();
    if(m.find(level)==m.end()) m[level]=node->val;
    if(node->right) q.push({node->right,level+1});
    if(node->left) q.push({node->left,level+1});   
    }
    vector<int>v;
    for(auto it : m){
    v.push_back(it.second);
    }
    return v;    
    }
};