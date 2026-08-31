class Solution {
public:
    long long  min_jump(int index,vector<int>&nums,vector<int>&dp){
    if(index==nums.size()-1) return 0;
    if(index>=nums.size()) return INT_MAX;
    if(dp[index]!=-1) return dp[index];
    long long ans= INT_MAX;
    for(int i=1;i<=nums[index];i++){
    ans=min(ans,1+min_jump(index+i,nums,dp));
    }
    return dp[index]=ans;    
    }
    int jump(vector<int>& nums) {
    vector<int>dp(nums.size(),-1);
    return min_jump(0,nums,dp);    
    }
};