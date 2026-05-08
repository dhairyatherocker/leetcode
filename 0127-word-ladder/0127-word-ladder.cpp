class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string>s;
    for(auto &it:wordList){
    s.insert(it);    
    }
    if(s.find(endWord)==s.end()) return 0;
    priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>pq;
    pq.push({1,beginWord});

    while(!pq.empty()){
    auto [level,node]=pq.top();
    if(node==endWord) return level;
    pq.pop();
    for(int i=0;i<node.size();i++){
    string temp=node;
    for(char j='a';j<='z';j++){
    temp[i]=j;
    if(s.find(temp)!=s.end()){
    pq.push({level+1,temp});
    s.erase(temp);
    }    
    }    
    }    
    } 
    return 0;  
    }
};