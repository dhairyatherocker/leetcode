class Solution {
public:
    int fabonacci(int n,vector<int>&dp){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=(fabonacci(n-1,dp)+fabonacci(n-2,dp)+fabonacci(n-3,dp));
    }
    int tribonacci(int n) {
    vector<int>dp(38,-1);
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    return fabonacci(n,dp);   
    }
};