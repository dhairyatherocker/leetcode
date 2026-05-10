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
    void traversal(TreeNode* root,vector<int>&v,int &key){
    if(root==NULL) return;
    traversal(root->left,v,key);
    if(root->val!=key) v.push_back(root->val);
    traversal(root->right,v,key);
    return;    
    }
    TreeNode* formtree(int left,int right,vector<int>&v){
    if(left>right) return NULL;
    int mid=(left+right)>>1;
    TreeNode* root=new TreeNode(v[mid]);
    root->left=formtree(left,mid-1,v);
    root->right=formtree(mid+1,right,v);
    return root;    
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
    vector<int>v;
    traversal(root,v,key);
    return formtree(0,v.size()-1,v);    
    }
};