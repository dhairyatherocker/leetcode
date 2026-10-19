class Solution {
public:
    bool dfs(int node,int prev_group,vector<int>&vis,vector<vector<int>>&adj){
    vis[node]=1-prev_group;
    for(auto it : adj[node]){
    if(vis[it]==-1 && dfs(it,vis[node],vis,adj)==false) return false;
    else if(vis[it]==vis[node]) return false;    
    }
    return true;    
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {    
    vector<int>vis(n+1,-1);
    vector<vector<int>>adj(n+1);
    for(auto it : dislikes){
    auto first=it[0];
    auto second=it[1];
    adj[first].push_back(second);
    adj[second].push_back(first);
    }
    for(int i=1;i<=n;i++){
    if(vis[i]==-1 && dfs(i,1,vis,adj)==false) return false;    
    }
    return true;
    }
};