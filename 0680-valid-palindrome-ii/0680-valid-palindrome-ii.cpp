class Solution {
public:
    // int min_delete(int index_1,int index_2,string &s,vector<vector<int>>&dp){
    // if(index_1>=index_2) return 0;
    // if(dp[index_1][index_2]!=-1) return dp[index_1][index_2];
    // int take;
    // if(s[index_1]==s[index_2]) take=min_delete(index_1+1,index_2-1,s,dp);
    // else take=1+min(min_delete(index_1+1,index_2,s,dp),min_delete(index_1,index_2-1,s,dp));
    // return dp[index_1][index_2]=take;    
    // }

    bool ispalindrome(int index_1,int index_2,string &s){
    while(index_1<=index_2){
    if(s[index_1]!=s[index_2]) return false;
    index_1++;
    index_2--;    
    } 
    return true;   
    } 
    bool validPalindrome(string s) {
    // vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
    // return min_delete(0,s.size()-1,s,dp)<=1?true:false;

   int index_1=0;
   int index_2=s.size()-1;
   while(index_1<=index_2){
   if(s[index_1]!=s[index_2] ) return ispalindrome(index_1+1,index_2,s) || ispalindrome(index_1,index_2-1,s);
   index_1++;
   index_2--;  
   }
   return true;
    }    
    
};