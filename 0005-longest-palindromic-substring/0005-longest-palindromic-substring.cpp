class Solution {
public:
    int findpalindrome(int start,int end,string &s,vector<vector
    <int>>&dp){
    if(start>=end) return 1;
    if(s[start]!=s[end]) return 0;
    if(dp[start][end]!=-1) return dp[start][end]; 
    return dp[start][end]=findpalindrome(start+1,end-1,s,dp); 
    }
    string longestPalindrome(string s) {
    int n=s.size();    
    vector<vector<int>>dp(n,vector<int>(n,-1));
    string ans="";
    for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
    if(findpalindrome(i,j,s,dp)==1 && ans.size()<(j-i+1)) ans=s.substr(i,j-i+1); 
    }}
    return ans;
    }
};