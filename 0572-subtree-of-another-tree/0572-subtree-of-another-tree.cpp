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
    bool inorder(TreeNode* root,TreeNode* subRoot){
    if(root==NULL && subRoot==NULL) return true;
    if((root==NULL && subRoot!=NULL) || (root!=NULL && subRoot==NULL)) return false;
    if(root->val!=subRoot->val) return false;
     bool left=inorder(root->left,subRoot->left);
    bool right=inorder(root->right,subRoot->right);
    if(!left || !right) return false;
    return true;
    }
    bool preorder(TreeNode* root,TreeNode* subRoot){
    if(root==NULL) return false;
    if(root->val==subRoot->val && inorder(root,subRoot)) return true; 
    bool left=preorder(root->left,subRoot);
    bool right=preorder(root->right,subRoot);
    if(left || right) return true;
    return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    return preorder(root,subRoot);    
    }
};