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
    TreeNode* traversal(int &index,vector<int>&nums,int mini ,int maxi){
    if(index>=nums.size() || nums[index]<=mini || nums[index]>=maxi) return NULL;
    TreeNode* root=new TreeNode(nums[index++]);
    root->left=traversal(index,nums,mini,root->val);
    root->right=traversal(index,nums,root->val,maxi);
    return root;    
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i=0;    
    return traversal(i,preorder,INT_MIN,INT_MAX);
    }
};