class Solution {
public:
    int characterReplacement(string s, int k) {
    int i=0;
    int j=0;
    unordered_map<char,int>m;
    int maxi=0;
    int maxlen=0;
    while(j<s.size()){
    m[s[j]]++;
    maxi=max(maxi,m[s[j]]);
    int rem=j-i+1-maxi;
    if(rem>k){
    while(rem>k){
    m[s[i]]-=1;
    i++;
    for(auto it : m) maxi=max(it.second,maxi);
    rem=j-i+1-maxi;    
    }    
    }
    maxlen=max(j-i+1,maxlen);
    j++;    
    }
    return maxlen;    
    }
};