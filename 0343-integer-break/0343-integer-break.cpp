class Solution {
public:
    int findbreak(int n,unordered_map<int,int>&dp){
    if(n==0) return 1;
    if(dp.find(n)!=dp.end()) return dp[n];
    int maxlen=INT_MIN;
    for(int i=1;i<=n;i++){
    maxlen=max(maxlen,i*findbreak(n-i,dp));
    }
    return dp[n]=maxlen;    
    }
    int integerBreak(int n) {
    unordered_map<int,int>dp;
    int maxlen=INT_MIN;
    for(int i=1;i<n;i++){
    maxlen=max(maxlen,i*findbreak(n-i,dp));
    }
    return maxlen;    
    }
};