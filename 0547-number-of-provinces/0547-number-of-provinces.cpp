class Solution {
public:
    void dfs(int index,vector<bool>&vis,vector<vector<int>>&adj){
    vis[index]=true;
    for(auto it : adj[index]){
    if(!vis[it]) dfs(it,vis,adj);    
    }
    return;    
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
    int n=isConnected.size();
    vector<bool>vis(n,false);
    vector<vector<int>>adj(n);
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
    if(i!=j && isConnected[i][j]==1){
    adj[i].push_back(j);
    adj[j].push_back(i);    
    }
    }}
    int count=0;
    for(int i=0;i<n;i++){
    if(!vis[i]){
    count++;
    dfs(i,vis,adj);    
    }    
    }
    return count;    
    }
};