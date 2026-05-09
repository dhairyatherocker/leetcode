class Solution {
public:
    bool dfs(int index,int prev_index,vector<int>&group,vector<bool>&vis,vector<vector<int>>&graph){
    vis[index]=true;
    group[index]=1-group[prev_index];
    for(auto it : graph[index]){
    if(vis[it] && group[it]==group[index]) return false;
    else if(!vis[it] && dfs(it,index,group,vis,graph)==false) return false;    
    }
    return true;    
    }
    bool isBipartite(vector<vector<int>>& graph) {
    int n=graph.size();    
    vector<bool>vis(n,false);
    vector<int>group(n+1,0);
    for(int i=0;i<n;i++){
    if(!vis[i] && dfs(i,n,group,vis,graph)==false) return false;    
    }
    return true;    
    }
};