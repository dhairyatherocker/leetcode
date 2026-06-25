class Solution {
public:
    int longestsubsequence(int index_1,int index_2,string &text1,string text2,vector<vector<int>>&dp){
    if(index_1>=text1.size() || index_2>=text2.size()) return 0;
    if(dp[index_1][index_2]!=-1) return dp[index_1][index_2];
    int ans;
    if(text1[index_1]==text2[index_2]) ans=1+longestsubsequence(index_1+1,index_2+1,text1,text2,dp);
    else ans=max(longestsubsequence(index_1+1,index_2,text1,text2,dp),longestsubsequence(index_1,index_2+1,text1,text2,dp));
    return dp[index_1][index_2]=ans;    
    }
    int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
    return longestsubsequence(0,0,text1,text2,dp);    
    }
};