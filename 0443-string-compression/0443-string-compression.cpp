class Solution {
public:
    int compress(vector<char>& chars) {
    int i=0;
    int j=0;
    string ans="";
    while(j<chars.size()){
    if(chars[j]!=chars[i]){
    ans=ans+chars[i];
    if(j-i>1) ans+=to_string(j-i);
    i=j;    
    }
    j++;    
    }
    ans=ans+chars[i];
    if(j-i>1) ans+=to_string(j-i);
    for(int i=0;i<ans.size();i++) chars[i]=ans[i];
    return ans.size();    
    }
};