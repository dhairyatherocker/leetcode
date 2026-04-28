class Solution {
public:
    int findpalindrome(int left,int right,string &s,vector<vector<int>>&dp){
    if(left>=right) return 1;
    if(dp[left][right]!=-1) return dp[left][right];
    if(s[left]!=s[right]) return 0;
    return dp[left][right]=findpalindrome(left+1,right-1,s,dp);
    }
    int countSubstrings(string s) {
    vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
    int count=0;
    for(int i=0;i<s.size();i++){
    for(int j=i;j<s.size();j++){
    if(findpalindrome(i,j,s,dp)==1) count++;    
    }    
    }
    return count;    
    }
};