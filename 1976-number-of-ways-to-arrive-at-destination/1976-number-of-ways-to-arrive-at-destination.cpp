class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
    int div=1e9+7;
    int m=roads.size();
    vector<long long>dis(n,LLONG_MAX);
    vector<int>ways(n,0);
    ways[0]=1;
    dis[0]=0;
    vector<vector<pair<int,int>>>adj(n);
    for(auto it : roads){
    int first=it[0];
    int second=it[1];
    int cost=it[2];
    adj[first].push_back({second,cost});
    adj[second].push_back({first,cost});    
    }
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
    pq.push({0,0});
    while(!pq.empty()){
    auto [cost,node]=pq.top();
    pq.pop();
    for(auto it :adj[node]){
    long long new_price=(cost+it.second);
    int new_node=it.first;
    if(dis[new_node]>new_price){
    dis[new_node]=new_price;
    ways[new_node]=ways[node];
    pq.push({new_price,new_node});    
    }
    else if(dis[new_node]==new_price){
    ways[new_node]=(ways[new_node]+ways[node])%div;
      
    }    
    }    
    }
    return ways[n-1];   
    }
};