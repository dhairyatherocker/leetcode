class Solution {
public:
    int jump(int index,vector<int>&nums,vector<int>&dp){
    if(index==nums.size()-1) return true;
    if(index>=nums.size()) return false;
    if(dp[index]!=-1) return dp[index];
    bool ans= false;
    for(int i=1;i<=nums[index];i++){
    if(jump(index+i,nums,dp)) return ans=true;
    }
    return dp[index]=ans;    
    }
    bool canJump(vector<int>& nums) {
    int maxi=INT_MIN;
    for(auto it : nums) maxi=max(it,maxi);   
    vector<int>dp(nums.size(),-1);
    return jump(0,nums,dp);    
    }
};