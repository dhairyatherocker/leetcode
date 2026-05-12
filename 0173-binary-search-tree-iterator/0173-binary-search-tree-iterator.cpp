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
class BSTIterator {
public:
    vector<int>ans;
    int pointer=0;
    void traversal(TreeNode* root){
    if(root==NULL) return;
    traversal(root->left);
    ans.push_back(root->val);
    traversal(root->right);
    return;
    }
    BSTIterator(TreeNode* root) {
    traversal(root);    
    }
    
    int next() {
    return ans[pointer++];    
    }
    
    bool hasNext() {
    if(pointer<ans.size()) return true;
    return false;    
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */