class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    unordered_map<int,int>m;
    int i=0;
    int j=0;
    int max_len=0;
    while(j<s.size()){
    if(m.find(s[j])==m.end()){
    m[s[j]]=j;
    max_len=max(max_len,j-i+1);    
    }
    else{
    max_len=max(max_len,j-i);    
    int end=m[s[j]];
    for(;i<=end;i++){
    m.erase(s[i]);    
    }
    m[s[j]]=j;
    }
    j++;
    }
    return max_len;    
    }
};