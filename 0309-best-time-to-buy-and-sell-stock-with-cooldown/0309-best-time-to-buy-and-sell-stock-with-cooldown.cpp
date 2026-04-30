class Solution {
public:
    int profit(int index,int action,vector<int>&prices,vector<vector<int>>&dp){
    if(index>=prices.size()) return 0;
    if(dp[index][action]!=-1) return dp[index][action];
    int pick=INT_MIN;
    int drop=INT_MIN;
    if(action==0){
     pick=-prices[index]+profit(index+1,1,prices,dp);
     drop=profit(index+1,0,prices,dp);    
    }
    else{
     pick=prices[index]+profit(index+2,0,prices,dp);
     drop=profit(index+1,1,prices,dp);    
    }
    return dp[index][action]=max(pick,drop);     
    }
    int maxProfit(vector<int>& prices) {
    vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
    return profit(0,0,prices,dp);    
    }
};