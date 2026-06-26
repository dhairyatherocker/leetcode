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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int,map<int,vector<int>>>m;
    queue<pair<TreeNode*,pair<int,int>>>q;
    q.push({root,{0,0}});
    while(!q.empty()){
    auto [node,pos]=q.front();
    int row=pos.first;
    int col=pos.second;
    m[col][row].push_back(node->val);    
    if(node->left!=NULL) q.push({node->left,{row+1,col-1}});
    if(node->right!=NULL) q.push({node->right,{row+1,col+1}});
    q.pop();   
    }
    vector<vector<int>>result;
    for(auto it : m){
    vector<int>ans;
    for(auto itr : it.second){
    vector<int>v=itr.second;
    sort(v.begin(),v.end());
    for(auto i : v) ans.push_back(i);    
    }
    result.push_back(ans);    
    }
    return result;    
    }
};