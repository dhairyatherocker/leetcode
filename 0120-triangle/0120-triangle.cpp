class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    
     int m=triangle.size();
    vector<int>prev=triangle[m-1];
     for(int i=m-2;i>=0;i--){
    vector<int>dp(triangle[i].size(),-1);
     for(int j=0;j<triangle[i].size();j++){
     int total=INT_MAX;      
     for(int k=0;k<2;k++){
     int ncol=j+k;
     if(ncol>=0 && ncol<triangle[i+1].size()) total=min(total,prev[ncol]+triangle[i][j]);   
     }
     dp[j]=total;
     }
     prev=dp;   
     }
     return prev[0];   
    }
};