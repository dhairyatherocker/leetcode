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
    void traversal(TreeNode* root,TreeNode* mark){
    if(root->left==NULL && root->right==NULL){
    if(mark->val>root->val) root->right=mark;
    else root->left=mark;
    return;    
    }
    if(root->val>mark->val){
    if(root->left==NULL){root->left=mark;
    return;}
    else traversal(root->left,mark); 
    }
     
    else{
    if(root->right==NULL){root->right=mark;
    return;}
    else traversal(root->right,mark);
    }
    return;    
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode* mark=new TreeNode(val);
    if(root==NULL) return mark;
    traversal(root,mark);
    return root;    
    }
};