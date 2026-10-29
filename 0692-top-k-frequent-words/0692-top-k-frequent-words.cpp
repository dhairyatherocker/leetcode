class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string,int>m;
    map<int,vector<string>>m_freq;
    for(int it=0;it<words.size();it++){
    if(m.find(words[it])==m.end()){
    m[words[it]]=1;
    m_freq[1].push_back(words[it]);    
    }
    else{
    int prev_freq=m[words[it]];
    m[words[it]]++;
   auto &v = m_freq[prev_freq];
    v.erase(find(v.begin(), v.end(), words[it]));
    m_freq[prev_freq+1].push_back(words[it]);    
    }    
    }
    vector<string>result;
    for(auto it=m_freq.rbegin();it!=m_freq.rend();it++){
    int freq=it->first;
    vector<string>temp=it->second;
    sort(temp.begin(),temp.end());
    for(int i=0;i<temp.size() && k>0;i++){
    result.push_back(temp[i]);
    k--;    
    }    
    }
    return result;
    }
};