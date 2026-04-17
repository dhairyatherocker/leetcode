class Solution {
public:
    bool findsubset(int index,int sum,vector<int>&nums,vector<vector<int>>&dp){
    if(index==nums.size()-1) return nums[index]==sum;
    if(dp[index][sum]!=-1) return dp[index][sum];
    int drop=findsubset(index+1,sum,nums,dp);
    int pick=false;
    if((sum-nums[index])>=0) pick=findsubset(index+1,sum-nums[index],nums,dp);
    return dp[index][sum]=pick || drop;    
    }
    bool canPartition(vector<int>& nums) {
    int sum=0;
    for(int i=0;i<nums.size();i++) sum+=nums[i];
    if(sum%2!=0) return false;
    vector<vector<int>>dp(nums.size(),vector<int>(sum,-1));
    return findsubset(0,sum/2,nums,dp);    
    }
};