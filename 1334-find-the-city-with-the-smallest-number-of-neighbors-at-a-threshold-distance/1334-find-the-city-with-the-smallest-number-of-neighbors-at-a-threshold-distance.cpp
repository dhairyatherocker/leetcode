class Solution {
public:
    int findways(int num,vector<vector<pair<int,int>>>&adj,int threshold,int n){
    queue<pair<int,int>>pq;
    vector<int>dis(n,INT_MAX);
    pq.push({num,0});
    dis[num]=0;
    while(!pq.empty()){
    auto [node,cost]=pq.front();
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
    int count=0;
    for(int i=0;i<n;i++){
    if(dis[i]<=threshold) count++;    
    }
    return count;    
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    int count=INT_MAX;
    int index;
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=0;i<edges.size();i++){
    int first=edges[i][0];
    int second=edges[i][1];
    int third=edges[i][2];
    adj[first].push_back({second,third});
    adj[second].push_back({first,third});    
    }
    for(int i=0;i<n;i++){
    int new_count=findways(i,adj,distanceThreshold,n);
    if(new_count<=count){
    count=new_count;
    index=i;
    }    
    }
    return index;    
    }
};