class Solution {
public:
    int minedit(int index_1,int index_2,string &word1,string &word2,vector<vector<int>>&dp){
    if(index_1<0) return index_2+1;
    if(index_2<0) return index_1+1;
    if(dp[index_1][index_2]!=-1) return dp[index_1][index_2];
    if(word1[index_1]==word2[index_2]) return dp[index_1][index_2]=minedit(index_1-1,index_2-1,word1,word2,dp);
    return dp[index_1][index_2]=1+min(minedit(index_1-1,index_2,word1,word2,dp),min(minedit(index_1-1,index_2-1,word1,word2,dp),minedit(index_1,index_2-1,word1,word2,dp)));    
    }
    int minDistance(string word1, string word2) {
    int n=word1.size();
    int m=word2.size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return minedit(n-1,m-1,word1,word2,dp);    
    }
};