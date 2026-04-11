class Solution {
public:
    int drow[4]={-1,0,1,0};
    int dcol[4]={0,1,0,-1};
    void dfs(int row,int col,vector<vector<char>>&grid){
    grid[row][col]='2';
    for(int i=0;i<4;i++){
    int nrow=drow[i]+row;
    int ncol=dcol[i]+col;
    if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[row].size() && grid[nrow][ncol]=='1') dfs(nrow,ncol,grid);    
    }
    return;
    }
    int numIslands(vector<vector<char>>& grid) {
     int count=0;   
     for(int i=0;i<grid.size();i++){
     for(int j=0;j<grid[i].size();j++){
     if(grid[i][j]=='1'){
     dfs(i,j,grid);
     count++;
     }    
     }   
     }
     return count;    
    }
};