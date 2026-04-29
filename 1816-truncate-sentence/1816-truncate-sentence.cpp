class Solution {
public:
    string truncateSentence(string s, int k) {
    string result="";
    queue<char>q;
    int count=0;
    for(int i=0;i<s.size();i++){
    if(s[i]==' '){
    string temp="";    
    while(!q.empty() && ((q.front()>='A' && q.front()<='Z')||(q.front()>='a' && q.front()<='z'))){
    temp+=q.front();
    q.pop();    
    }
    if(temp!="") count++;
    result=result+" "+temp;    
    }
    else if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')) q.push(s[i]);
    if(count==k) break;    
    }
    
    if(!q.empty() && count<k){
    string temp="";
    while(!q.empty() && count==k-1){
    temp+=q.front();
    q.pop();    
    }
    result=result+" "+temp; 
    }


    return result.substr(1,result.size()-1);    
    }
};