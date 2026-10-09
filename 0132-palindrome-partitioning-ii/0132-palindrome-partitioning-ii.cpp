class Solution {
public:
    bool pal(int i,int j,string &s){
    while(i<j){
    if(s[i]!=s[j]) return false;
    i++;
    j--;    
    }
    return true;        
    }
    int palindrome(int i, int j, string &s,
                   vector<vector<int>>& dp) {
        if (i >= j || pal(i, j, s)) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int ways = INT_MAX;

        for (int k = i; k < j; k++) {
            if (pal(i, k, s)) {
                ways = min(ways,
                           1 + palindrome(k + 1, j, s, dp));
            }
        }

        return dp[i][j] = ways;
    }
    int minCut(string s) {
    vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));

    return palindrome(0,s.size()-1,s,dp);    
    }
};