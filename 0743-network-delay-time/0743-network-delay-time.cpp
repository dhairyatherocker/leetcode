class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) { 
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=0;i<times.size();i++){
    int first=times[i][0];
    int second=times[i][1];
    int third=times[i][2];
    adj[first].push_back({second,third});    
    }
    vector<int>dis(n+1,INT_MAX);
    queue<pair<int,int>>pq;
    pq.push({k,0});
    dis[k]=0;

    while(!pq.empty()){
    auto mark=pq.front();
    int node=mark.first;
    int cost=mark.second;
    pq.pop();
    for(auto it : adj[node]){
    int new_node=it.first;
    int new_cost=it.second+cost;
    if(new_cost<dis[new_node]){
    dis[new_node]=new_cost;
    pq.push({new_node,new_cost});    
    }    
    }    
    }
    int maxi=0;
    for(int i=1;i<=n;i++){
    if(dis[i]==INT_MAX) return -1;
    maxi=max(maxi,dis[i]);    
    }
    return maxi;       
    }
};