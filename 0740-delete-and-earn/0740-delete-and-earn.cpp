// class Solution {
// public:
    
//     int findmaxpoints(int index,int prev,vector<int>&nums,vector<vector<int>>&dp,unordered_map<int,int>&m){
//      if(index>=nums.size()) return 0;
//      if(dp[index][prev+1]!=-1) return dp[index][prev+1];
//      int pick=INT_MIN;
//      int drop=INT_MIN;
//      if(prev==-1 || nums[prev]+1!=nums[index]) pick=(m[nums[index]]*nums[index])+findmaxpoints(index+1,index,nums,dp,m);
//      drop=findmaxpoints(index+1,prev,nums,dp,m);
//      return dp[index][prev+1]=max(pick,drop);   
//     }
//     int deleteAndEarn(vector<int>& nums) {
//     sort(nums.begin(),nums.end());
//     unordered_map<int,int>m;
//     for(auto it : nums){
//     if(m.find(it)!=m.end()){
//     m[it]++;
//     m.erase(it);
//     }
//     else m[it]=1;    
//     }
//     vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
   
//     return findmaxpoints(0,-1,nums,dp,m);    
//     }
// };
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        // Step 1: find max value
        int maxVal = *max_element(nums.begin(), nums.end());

        // Step 2: build points array
        vector<int> points(maxVal + 1, 0);
        for(int x : nums) {
            points[x] += x;   // add value
        }

        // Step 3: House Robber DP
        vector<int> dp(maxVal + 1, 0);

        dp[0] = points[0];
        dp[1] = max(points[0], points[1]);

        for(int i = 2; i <= maxVal; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + points[i]);
        }

        return dp[maxVal];
    }
};