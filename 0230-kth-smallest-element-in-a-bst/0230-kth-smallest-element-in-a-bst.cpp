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
    void traversal(TreeNode* root,int &mark,int &k){
    if(root==NULL) return;
    traversal(root->left,mark,k);
    if(k==1){
    mark=root->val;   
    }
    traversal(root->right,mark,--k);
    }
    int kthSmallest(TreeNode* root, int k) {
    int mark;
    traversal(root,mark,k);
    return mark;    
    }
};