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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n=edges.size()+1;    
    rank.resize(n,1);
    parent.resize(n,0);
    int first_ans;
    int second_ans;
    for(int i=0;i<n;i++) parent[i]=i;
    for(int i=0;i<edges.size();i++){
    int first=find(edges[i][0]);
    int second=find(edges[i][1]);
    if(first==second){first_ans=edges[i][0];
    second_ans=edges[i][1];
    }
    else Union(edges[i][0],edges[i][1]);    
    }
    return {first_ans,second_ans};
    }
};