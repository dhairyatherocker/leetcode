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
    int traversal(TreeNode* root,int low,int high){
    if(root==NULL) return 0;
    int left=traversal(root->left,low,high);
    int right=traversal(root->right,low,high);
    int sum=left+right;
    if(root->val>=low && root->val<=high) sum+=root->val;
    return sum;     
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
    return traversal(root,low,high);    
    }
};