class Solution {
public:
    int drow[4]={0,1};
    int dcol[4]={1,0};
    int minsum(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&dp){
    if(row==grid.size()-1 && col==grid[0].size()-1) return 0;
    if(dp[row][col]!=-1) return dp[row][col];
    int total=INT_MAX;
    for(int i=0;i<2;i++){
    int nrow=drow[i]+row;
    int ncol=col+dcol[i];
    if((nrow>=0 && nrow<grid.size()) && (ncol>=0 && ncol<grid[0].size())) total=min(total,grid[nrow][ncol]+minsum(nrow,ncol,grid,dp));    
    } 
    return dp[row][col]=total;   
    }
    int minPathSum(vector<vector<int>>& grid){
    vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
    return grid[0][0]+minsum(0,0,grid,dp);    
    }
};