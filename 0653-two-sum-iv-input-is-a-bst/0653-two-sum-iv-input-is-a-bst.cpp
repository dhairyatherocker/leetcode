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
    bool traversal(TreeNode* root,int &k,unordered_map<int,int>&m){
    if(root==NULL) return false;
    if(traversal(root->left,k,m)==true) return true;
    int rem=k-root->val;
    if(m.find(rem)!=m.end()) return true;
    else m[root->val]=0;
    if(traversal(root->right,k,m)==true) return true;
    return false;    
    }
    bool findTarget(TreeNode* root, int k) {
    unordered_map<int,int>m;
    return traversal(root,k,m);    
    }
};