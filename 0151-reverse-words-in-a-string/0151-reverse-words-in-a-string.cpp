class Solution {
public:
    string reverseWords(string s) {
    stack<char>st;
    string ans="";
    for(int i=s.size()-1;i>=0;i--){
    if(s[i]!=' ') st.push(s[i]);    
    if(i==0 || s[i]==' ' && !st.empty()){
    while(!st.empty()){
    ans+=st.top();
    st.pop();    
    }
     if(s[i]==' ') ans+=" ";     
    }

    
    }
    int i=0;
    while(ans[i]==' ') i++;
    int j=ans.size()-1;
    while(ans[j]==' ') j--;
   return ans.substr(i,j-i+1);

    }
};