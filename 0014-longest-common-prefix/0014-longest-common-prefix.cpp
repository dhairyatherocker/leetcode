class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    string ans="";
    string match=strs[0];
    for(int k=1;k<strs.size();k++){
    int i=0;
    int j=0;
    while(i<match.size() && j<strs[k].size() && strs[k][j]==match[i]){
    ans+=match[i];
    i++;
    j++;    
    }
    match=ans;
    ans="";    
    }
    return match;   
    }
};