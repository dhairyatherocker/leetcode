class Solution {
public:
    int last_row;
    int last_col;
    int drow[2]={0,1};
    int dcol[2]={1,0};
    int ways(int row,int col,vector<vector<int>>&dp){
    if(row==last_row-1 && last_col-1==col) return 1;
    if(dp[row][col]!=-1) return dp[row][col];
    int total=0;
    for(int i=0;i<2;i++){
    int nrow=drow[i]+row;
    int ncol=dcol[i]+col;
    if((nrow>=0 && nrow<last_row) && (ncol>=0 && ncol<last_col)) total+=ways(nrow,ncol,dp);   
    }
    return dp[row][col]=total;    
    }
    int uniquePaths(int m, int n) {
    last_row=m;
    last_col=n;
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return ways(0,0,dp);    
    }
};