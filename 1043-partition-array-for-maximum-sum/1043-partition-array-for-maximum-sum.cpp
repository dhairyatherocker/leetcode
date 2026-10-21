class Solution {
public:
    int max_partition(int start,int end,vector<int>&arr,int k,vector<vector<int>>&dp){
    if(start>end) return 0;
    // if(start==end) return arr[start];
    if(dp[start][end]!=-1) return dp[start][end];
    int maxi=INT_MIN;
    int max_num=0;
    for(int i=start;i<start+k && i<arr.size();i++){
    max_num=max(max_num,arr[i]);
    maxi=max((i-start+1)*max_num+max_partition(i+1,end,arr,k,dp),maxi);
    }
    return dp[start][end]=maxi;    
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
    vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),-1));
    return max_partition(0,arr.size()-1,arr,k,dp);    
    }
};