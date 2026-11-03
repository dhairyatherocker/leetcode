class Solution {
public:
    string reorganizeString(string s) {
    unordered_map<char,int>m;
    int maxi=0;
    int n=s.size();
    priority_queue<pair<int,char>>pq;
    for(auto it : s) m[it]++;
    for(auto it : m){
    maxi=max(maxi,it.second);
    pq.push({it.second,it.first});
    }
   
    string ans="";
    while(!pq.empty() && pq.size()>=2){
    auto first=pq.top();
    pq.pop();
    auto second=pq.top();
    pq.pop();
    ans+=first.second;
    ans+=second.second;
    if((first.first-1)>0) pq.push({first.first-1,first.second});
    if((second.first-1)>0) pq.push({second.first-1,second.second});    
    }
    while(!pq.empty() && pq.size()==1){
    auto first=pq.top();
    if(first.first>=2) return "";
    ans+=first.second;
    pq.pop();    
    }
    return ans;    
    }
};