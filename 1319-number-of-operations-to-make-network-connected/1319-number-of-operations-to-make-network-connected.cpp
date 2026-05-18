class Solution {
public:
    vector<int>rank;
    vector<int>parent;
    int find(int x){
    if(x==parent[x]) return x;
    return parent[x]=find(parent[x]);    
    }
    void Union(int x,int y){
    int x_parent=find(x);
    int y_parent=find(y);
    if(x_parent==y_parent) return;
    else if(rank[x_parent]>rank[y_parent]) parent[y_parent]=x_parent;
    else if(rank[x_parent]<rank[y_parent]) parent[x_parent]=y_parent;
    else{
    parent[x_parent]=y_parent;
    rank[y_parent]++;    
    }    
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
    int count=0;
    int groups=0;
    rank.resize(n,1);
    parent.resize(n,0);
    for(int i=0;i<n;i++) parent[i]=i;
    unordered_set<int>s;
    for(int i=0;i<connections.size();i++){
    int first=connections[i][0];
    int second=connections[i][1];
    if(find(first)==find(second)) count++;
    else Union(first,second);    
    }
    for(int i=0;i<n;i++){
    s.insert(find(i));
    }
    if((s.size()-1)>count) return -1;
    return s.size()-1;
    }
    
};