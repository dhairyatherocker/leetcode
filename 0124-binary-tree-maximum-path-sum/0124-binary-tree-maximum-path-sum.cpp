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
    int traversal(TreeNode* root,int &maxi){
    if(root==NULL) return 0;
    int left=traversal(root->left,maxi);
    int right=traversal(root->right,maxi);
    int max_one=root->val+max(left,right);
    int max_two=max(root->val+left+right,maxi);
    maxi=max(max(max_one,max_two),root->val);
    return max(max(left,right)+root->val,root->val);    
    }
    int maxPathSum(TreeNode* root) {
    int maxi=INT_MIN;
    traversal(root,maxi);
    return maxi;    
    }
};