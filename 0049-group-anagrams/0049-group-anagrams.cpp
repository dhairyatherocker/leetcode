class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<vector<int>,vector<string>>m;
    vector<vector<string>>res;
    for(int i=0;i<strs.size();i++){
    vector<int>hash(26,0);
    for(int j=0;j<strs[i].size();j++){
    hash[strs[i][j]-'a']++;     
    }
    m[hash].push_back(strs[i]);    
    }
    for(auto it : m){
    res.push_back(it.second);    
    } 
    return res;   
    }
};