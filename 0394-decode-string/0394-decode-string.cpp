class Solution {
public:
    string convert(string num,string dummy){
    string result="";
    int j=stoi(num);
    for(int i=1;i<=j;i++){
    result+=dummy;    
    }
    return result;    
    }

    string decodeString(string s) {
    stack<string>st;
    for(int i=0;i<s.size();i++){
    if(s[i]!=']') st.push(string(1,s[i]));
    else{
    string dummy="";    
    while(st.top()!="["){
    dummy=st.top()+dummy;
    st.pop();    
    }
    st.pop();
    string num="";
    while(!st.empty() && !st.top().empty() && isdigit(st.top()[0])){
    num=st.top()+num;
    st.pop();    
    }
    string sr=convert(num,dummy);
    st.push(sr); 
    }    
    }
    string result="";
    while(!st.empty()){
    result=st.top()+result;
    st.pop();
    }
    return result;    
    }
};