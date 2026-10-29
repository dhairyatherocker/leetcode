class Solution {
public:
    vector<int> partitionLabels(string s) {
    vector<int>result;
    unordered_map<char,int>m;
    for(auto it : s) m[it]++;
    unordered_set<char>st;
    int last=0;
    int formed=0;
    for(int i=0;i<s.size();i++){
    st.insert(s[i]);
    m[s[i]]--;
    if(m[s[i]]==0) formed++;
    if(formed==st.size()){
    st.clear();
    formed=0;
    result.push_back(i+1-last);
    last=i+1;    
    }
    }
    return result;    
    }
};