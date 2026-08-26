class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    unordered_map<char,int>m;
    int i=0;
    int j=0;
    int n=s.size();
    int maxlen=0;
    while(j<n){
    if(m.find(s[j])==m.end()){
    maxlen=max(j-i+1,maxlen);
    m[s[j]]=j;    
    }
    else{
   
    int end=m[s[j]];
    int mover=i;
    for(;mover<=m[s[j]];mover++) m.erase(s[mover]);
    i=mover;
    m[s[j]]=j;    
    }
    j++;    
    }
    return maxlen;     
    }
};