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
    int cameras=0;
    int traversal(TreeNode* &root){
    if(root==NULL) return 0;
    int left=traversal(root->left);
    int right=traversal(root->right);
    if(left==-1 || right==-1){
    cameras++;
    return 1;    
    }
    else if(left==1 || right==1) return 0;
    return -1;    
    }
    int minCameraCover(TreeNode* root) {
    int response=traversal(root);
    if(response==-1) cameras++;
    return cameras;    
    }
};