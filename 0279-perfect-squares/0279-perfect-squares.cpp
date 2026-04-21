class Solution {
public:
    int perfectsquares(int n,vector<int>&dp){
    if(n==0){   
    return 0;    
    }
    if(dp[n]!=-1) return dp[n];
    int maxlen=INT_MAX;
    for(int i=1;i*i<=n;i++){
    maxlen=min(maxlen,1+perfectsquares((n-i*i),dp));    
    }
    return dp[n]=maxlen;    
    }
    int numSquares(int n) {
    int maxlen=INT_MAX;
    vector<int>dp(n+1,-1);
    return perfectsquares(n,dp);
        
    }
};