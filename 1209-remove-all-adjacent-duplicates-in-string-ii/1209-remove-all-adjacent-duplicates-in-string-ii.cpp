class Solution {
public:
    string removeDuplicates(string s, int k) {
    stack<pair<char,int>>st;
    for(int i=0;i<s.size();i++){
    if(!st.empty()){
    auto [letter,freq]=st.top();
    if(letter==s[i]){
    if(freq+1==k) st.pop();    
    else{ st.pop();
    st.push({letter,freq+1});}    
    }
    else st.push({s[i],1});    
    }
    else{
    st.push({s[i],1});    
    }    
    }
    string result="";
    while(!st.empty()){
    auto [letter,freq]=st.top();
    st.pop();
   result = string(freq, letter)+result;    
    }
    return result;    
    }
};