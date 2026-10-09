class Solution {
public:
    int ways(int index,int prev,string &s,vector<vector<int>>&dp){
    if(index>=s.size()) return 1;
    if(dp[index][prev]!=-1) return dp[index][prev];
    int take;
    if(s[index]=='0'){
    if(index>0 && prev==1 && (s[index-1]=='1' || s[index-1]=='2')){
    take=ways(index+1,0,s,dp);}
    else return 0;
    }
    else if(prev==1){
    if(index>0 && stoi(s.substr(index-1,2))>0 &&  stoi(s.substr(index-1,2))<27 ) take=ways(index+1,0,s,dp)+ways(index+1,1,s,dp);
    else take=ways(index+1,1,s,dp);    
    } 
    else take=take=ways(index+1,1,s,dp);
    return dp[index][prev]=take;   
    }
    int numDecodings(string s) {
    vector<vector<int>>dp(s.size(),vector<int>(2,-1));
    return ways(0,1,s,dp);       
    }
};