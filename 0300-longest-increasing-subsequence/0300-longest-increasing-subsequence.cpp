class Solution {
public:
    int subsequence(int index,int prev_index,vector<int>&nums,vector<vector<int>>&dp){
    if(index>nums.size()) return 0;
    if(dp[index][prev_index]!=-1) return dp[index][prev_index];

    int pick=INT_MIN;
    if(prev_index==0 || nums[index-1]>nums[prev_index-1]) pick=1+subsequence(index+1,index,nums,dp);
    int drop=subsequence(index+1,prev_index,nums,dp);
    return dp[index][prev_index]=max(drop,pick);

    }
    int lengthOfLIS(vector<int>& nums) {
      vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
      return subsequence(1,0,nums,dp);  
    }
};