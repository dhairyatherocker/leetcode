class Solution {
public:
    int countGoodSubstrings(string s) {
    int count=0;
    // unordered_set<string>st;
    if(s.size()<3) return 0;
    for(int i=0;i<s.size()-2;i++){
    unordered_set<char>m;
    string trav=""; 
    for(int j=i;j<i+3;j++){
    trav+=s[j];
    m.insert(s[j]);
    if(trav.size()==3 && m.size()==3) count++;
    }    
    }
    return count;    
    }
};