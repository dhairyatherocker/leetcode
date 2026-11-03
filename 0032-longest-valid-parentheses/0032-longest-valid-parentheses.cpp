class Solution {
public:
    // int longestValidParentheses(string s) {
    // vector<int>trace;
    // stack<int>q;
    // for(int i=0;i<s.size();i++){
    // if(s[i]=='('){
    // trace.push_back(0);
    // q.push(trace.size()-1);    
    // }
    // else if(s[i]==')' && !q.empty()){
    // int index=q.top();
    // q.pop();
    // trace[index]=2;    
    // }    
    // }
    // int sum=0;
    // int max_len=0;
    // for(int i=0;i<trace.size();i++){
    // if(trace[i]==0) sum=0;
    // else{
    // sum+=trace[i];
    // max_len=max(max_len,sum);    
    // }
    // }
    // return max_len;

    // }
    int longestValidParentheses(string s) {

    vector<int> trace;
    stack<int> st;

    for(int i=0; i<s.size(); i++){

        if(s[i]=='('){
            trace.push_back(0);
            st.push(i);
        }
        else{
            trace.push_back(0);

            if(!st.empty()){
                int index=st.top();
                st.pop();

                trace[index]=1;
                trace[i]=1;
            }
        }
    }

    int sum=0;
    int max_len=0;

    for(int i=0; i<trace.size(); i++){

        if(trace[i]==0){
            sum=0;
        }
        else{
            sum++;
            max_len=max(max_len,sum);
        }
    }

    return max_len;
}
};