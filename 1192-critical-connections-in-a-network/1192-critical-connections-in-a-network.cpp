class Solution {
public:
    vector<vector<int>>result;
    int timer=1;
    void dfs(int index,int parent,vector<int>&low,vector<int>&tim,vector<bool>&vis,vector<vector<int>>&adj){
    vis[index]=true;
    low[index]=tim[index]=timer;
    for(auto it : adj[index]){
    if(it==parent) continue;    
    if(!vis[it]){
    timer++;    
    dfs(it,index,low,tim,vis,adj);
    low[index]=min(low[index],low[it]);
    if(low[it]>tim[index]) result.push_back({index,it});    
    }
    else{
    low[index]=min(low[it],low[index]);     
    }    
    }    
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>>adj(n);
    for(auto it :connections){
    int first=it[0];
    int second=it[1];
    adj[first].push_back(second);
    adj[second].push_back(first);    
    }
    vector<int>tim(n);
    vector<int>low(n);
    vector<bool>vis(n,false);
    dfs(0,-1,low,tim,vis,adj);
    return result;    
    }
};