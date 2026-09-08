class Solution {
public:
    bool isIsomorphic(string s, string t) {
    if(s.size()!=t.size()) return false;
    unordered_map<char,char>m;
    unordered_set<char>st;
    for(int i=0;i<s.size();i++){
    char s_letter=s[i];
    char t_letter=t[i];
    if(m.find(s_letter)!=m.end() && m[s_letter]!=t_letter) return false;
    
    else if(m.find(s_letter)==m.end()){
    if(st.find(t_letter)!=st.end()) return false;    
    m[s_letter]=t_letter;
    st.insert(t_letter);
    }    
    }
    return true;    
    }
};