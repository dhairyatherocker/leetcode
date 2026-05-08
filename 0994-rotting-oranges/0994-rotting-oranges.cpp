class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    int max_time=0;
    queue<pair<int,pair<int,int>>>q;
    for(int i=0;i<grid.size();i++){
    for(int j=0;j<grid[i].size();j++){
    if(grid[i][j]==2) q.push({0,{i,j}});    
    }    
    }
    int drow[]={-1,0,1,0};
    int dcol[]={0,1,0,-1};
    while(!q.empty()){
    auto [time,node]=q.front();
    max_time=max(max_time,time);
    int row=node.first;
    int col=node.second;
    q.pop();
    for(int i=0;i<4;i++){
    int nrow=drow[i]+row;
    int ncol=dcol[i]+col;
    if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && grid[nrow][ncol]==1){
    grid[nrow][ncol]=2;
    q.push({time+1,{nrow,ncol}});    
    }    
    }
    }
    for(int i=0;i<grid.size();i++){
    for(int j=0;j<grid[i].size();j++){
    if(grid[i][j]==1) return -1;    
    }    
    }
    return max_time;    
    }
};