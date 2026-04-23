class Solution {
public:
    long long findcoin(int index,int amount,vector<int>&coins,vector<vector<long long>>&dp){
    if(index>=coins.size()){
    if(amount==0) return 0;
    return INT_MAX;    
    }
    if(amount==0) return 0;
    if(dp[index][amount]!=-1) return dp[index][amount];
    long long drop=findcoin(index+1,amount,coins,dp);
    long long pick=INT_MAX;
    if(coins[index]<=amount) pick=1+findcoin(index,amount-coins[index],coins,dp);
    return dp[index][amount]=min(pick,drop);    
    }
    int coinChange(vector<int>& coins, int amount) {
    vector<vector<long long>>dp(coins.size(),vector<long long>(amount+1,-1));
    sort(coins.begin(),coins.end());
    long long ans=findcoin(0,amount,coins,dp);
    return ans==INT_MAX?-1:ans;    
    }
};