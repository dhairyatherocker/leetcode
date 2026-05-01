class Solution {
public:
   int longestsubsequence(int index1,int index2,string &s1,string &s2,vector<vector<int>>&dp){
   if(index1>=s1.size() || index2>=s2.size()) return 0;
   if(dp[index1][index2]!=-1) return dp[index1][index2];
   int ele;
   if(s1[index1]==s2[index2]) ele=1+longestsubsequence(index1+1,index2+1,s1,s2,dp);
   else ele=max(longestsubsequence(index1+1,index2,s1,s2,dp),longestsubsequence(index1,index2+1,s1,s2,dp));
   return dp[index1][index2]=ele;  
   }
    int longestPalindromeSubseq(string s) {
    string s1=s;
    string s2=s;
    reverse(s2.begin(),s2.end());
    vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
    return longestsubsequence(0,0,s1,s2,dp);    
    }
};