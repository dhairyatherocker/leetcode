class Solution {
public:
    string removeKdigits(string num, int k) {
    stack<char>st;
    for(int i=0;i<num.size();i++){
    while(!st.empty() && st.top()-'0'>num[i]-'0' && k>0){
    st.pop();
    k--;    
    }
    st.push(num[i]);
    }
    while(k>0 && !st.empty()){
    k--;
    st.pop();    
    }
    string res="";

    while(!st.empty()){
    res+=st.top();
    st.pop();
    }
    while(res.size()!=0 && res[res.size()-1]=='0') res.pop_back();
    reverse(res.begin(),res.end());
    return res.size()==0?"0":res;
    }
};