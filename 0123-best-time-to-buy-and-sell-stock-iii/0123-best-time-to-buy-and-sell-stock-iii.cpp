class Solution {
public:
    int profit(int index,int transaction,int action,vector<int>&prices,vector<vector<vector<int>>>&dp){
    if(index>=prices.size()) return 0;
    if(transaction>=4) return 0;
    if(dp[index][transaction][action]!=-1) return dp[index][transaction][action];
    int dump=INT_MIN;
    int pick=INT_MIN;
    if(action==0){
    pick=-prices[index]+profit(index+1,transaction+1,1,prices,dp);
    dump=profit(index+1,transaction,0,prices,dp);    
    }
    else if(action==1){
     pick=prices[index]+profit(index+1,transaction+1,0,prices,dp);
    dump=profit(index+1,transaction,1,prices,dp);       
    }
    return dp[index][transaction][action]=max(pick,dump);     
    }
    int maxProfit(vector<int>& prices) {
    vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(5,vector<int>(2,-1)));
    return profit(0,0,0,prices,dp);    
    }
};