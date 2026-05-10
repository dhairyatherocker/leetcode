class Solution {
public:
    int drow[8]={-1,-1,0,1,1,1,0,-1};
    int dcol[8]={0,1,1,1,0,-1,-1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
  priority_queue<pair<int,int>,
               vector<pair<int,int>>,
               greater<pair<int,int>>> pq;
    if(grid[0][0]==1) return -1;

    vector<vector<int>>dis(grid.size(),vector<int>(grid[0].size(),INT_MAX));
    dis[0][0]=1;
    pq.push({0,0});
    while(!pq.empty()){
    auto [row,col]=pq.top();
    pq.pop();
    for(int i=0;i<8;i++){
    int nrow=drow[i]+row;
    int ncol=dcol[i]+col;
    if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() &&  dis[nrow][ncol]>dis[row][col]+1 && grid[nrow][ncol]==0){
    dis[nrow][ncol]=dis[row][col]+1;
    pq.push({nrow,ncol});    
    }    
    }    
    }
    int ans= dis[grid.size()-1][grid[0].size()-1];
    return ans==INT_MAX?-1:ans;     
    }
};