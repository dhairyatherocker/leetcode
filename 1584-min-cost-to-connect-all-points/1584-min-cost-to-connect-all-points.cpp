class Solution {
public:
    int prims(int index,vector<vector<pair<int,int>>>&adj){

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    pq.push({0,0});
    int cost=0;
    vector<bool>vis(adj.size(),false);
    while(!pq.empty()){
    auto [weight,node]=pq.top();
    pq.pop();
    if(vis[node]==true) continue;
    vis[node]=true;
    cost+=weight;
    for(auto it : adj[node]){
    if(!vis[it.second]) pq.push({it.first,it.second});    
    }    
    }
    return cost;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
    vector<vector<pair<int,int>>>adj(points.size());
    for(int i=0;i<points.size();i++){
    for(int j=i+1;j<points.size();j++){
    int x1=points[i][0];
    int y1=points[i][1];
    int x2=points[j][0];
    int y2=points[j][1];
    int d=abs(x1-x2)+abs(y1-y2);
    adj[i].push_back({d,j});
    adj[j].push_back({d,i});
    }    
    }
    return prims(0,adj);    
    }
};