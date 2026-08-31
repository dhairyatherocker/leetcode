class Solution {
public:
    int paranthesis(int index,string &s,int count,vector<vector<int>>&dp){
    if(index==s.size()){
     if(count==0) return true;
      return false;    
    } 
    if(count<0) return false;
    if(dp[index][count]!=-1) return dp[index][count];
    bool ans=false;
    if(s[index]=='(') ans=paranthesis(index+1,s,count+1,dp);
    else if(s[index]==')') ans=paranthesis(index+1,s,count-1,dp);
    else{
    if(paranthesis(index+1,s,count-1,dp) || paranthesis(index+1,s,count+1,dp) || paranthesis(index+1,s,count,dp)) ans=true;    
    }
    return dp[index][count]=ans;
    }
    bool checkValidString(string s) {
    vector<vector<int>>dp(s.size(),vector<int>(s.size()+1,-1));
    return paranthesis(0,s,0,dp);
    }
};