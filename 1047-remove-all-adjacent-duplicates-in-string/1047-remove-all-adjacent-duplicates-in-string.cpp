class Solution {
public:
    string removeDuplicates(string s) {
    stack<char>st;
    int n=s.size();
    for(int i=n-1;i>=0;i--){
    if(!st.empty() && st.top()==s[i]) st.pop();
    else st.push(s[i]);    
    }
    string formed="";
    while(!st.empty()){
    char letter=st.top();    
    formed=formed+letter;
    st.pop();
    }
    return formed;    
    }
};