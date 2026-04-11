class Solution {
public:
    string removeStars(string s) {
    //  stack<char>st;
    //  for(int i=0;i<s.size();i++){
    //  if(s[i]=='*' && !st.empty()) st.pop();
    //  else st.push(s[i]);   
    //  }
    //  string res="";
    //  while(!st.empty()){
    //  res+=st.top();
    //  st.pop();
    //  }
    //  reverse(res.begin(),res.end());
    //  return res;   

    string res="";
    for(int i=0;i<s.size();i++){
    if(s[i]=='*' && res.size()!=0) res.pop_back();
    else res+=s[i];    
    }
    return res;
    }
};