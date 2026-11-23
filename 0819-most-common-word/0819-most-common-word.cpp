class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
    map<string,int>m;
    unordered_set<string>s;
    for(auto it : banned) s.insert(it);
    string ans="";
    for(int i=0;i<paragraph.size();i++){
    if((paragraph[i]>='A' && paragraph[i]<='Z') || (paragraph[i]>='a' && paragraph[i]<='z')) ans+=tolower(paragraph[i]);
   
    else if(ans.size()>=1){
    if( s.find(ans)!=s.end()){
    ans="";
    continue;    
    }    
    m[ans]++;
    ans="";
    }     
    }
    if(ans.size()>=1 ) m[ans]++;
    int maxi=INT_MIN;
    for(auto it : m){
    maxi=max(maxi,it.second);    
    }
    for(auto it : m){
    if(it.second==maxi) return it.first;    
    }
    return "";
    }
};