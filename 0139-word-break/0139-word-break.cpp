class Solution {
public:
    int word(int i,int j,string &s,unordered_set<string>&st,vector<vector<int>>&dp){
    if(i>j) return true;
    if(dp[i][j]!=-1) return dp[i][j];
    string form="";
    for(int k=i;k<=j;k++){
    form+=s[k];
    if(st.find(form)!=st.end() && word(k+1,j,s,st,dp)==1) return dp[i][j]=true;    
    }
    return dp[i][j]=0;    
    }
    bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string>st;
    for(auto it : wordDict) st.insert(it);    
    vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
    return word(0,s.size()-1,s,st,dp);    
    }
};