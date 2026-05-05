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
    void traversal(TreeNode* root, TreeNode* &mark,int &val){
    if(root==NULL) return;
    traversal(root->left,mark,val);
    traversal(root->right,mark,val);
    if(root->val==val) mark=root;
    return;    
    }
    TreeNode* searchBST(TreeNode* root, int val) {
    TreeNode* mark=NULL;
    traversal(root,mark,val);
    return mark;    
    }
};