class Solution {
public:
    int dcol[3]={-1,0,1};
    int findpath(int index,int robo_1,int robo_2,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
    if(index==grid.size()) return 0;
    if(dp[index][robo_1][robo_2]!=-1) return dp[index][robo_1][robo_2];

    int cherry=robo_1==robo_2?grid[index][robo_1]:(grid[index][robo_1]+grid[index][robo_2]);
    int total=INT_MIN;
    for(int i=0;i<3;i++){
    int col_1=robo_1+dcol[i];
    if(col_1<0 || col_1>=grid[0].size()) continue;
    for(int j=0;j<3;j++){
    int col_2=robo_2+dcol[j];
    if(col_2>=0 &&  col_2<grid[0].size()) total=max(total,cherry+findpath(index+1,col_1,col_2,grid,dp));    
    }    
    }
    return dp[index][robo_1][robo_2]=total;   
    }
    int cherryPickup(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
    return findpath(0,0,n-1,grid,dp);   
    }
};