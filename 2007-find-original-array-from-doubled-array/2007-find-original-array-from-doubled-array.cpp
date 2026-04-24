class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
    int n=changed.size();
    if(n%2!=0) return {};
    vector<int>v;
    sort(changed.begin(),changed.end());
    int j=changed.size()-1;
    vector<int>hash(1e5+1,0);
    for(int i=0;i<changed.size();i++) hash[changed[i]]++;
    while(j>=0){
    if(hash[changed[j]]!=0){
    int div=changed[j]/2;
    int rem=changed[j]%2;
    if(hash[div]==0 || changed[j]==1 || rem!=0) return {};
    v.push_back(div);
    hash[div]--;
    hash[changed[j]]--;
    } 
    
    j--;   
    
    
    } 
    return v;   
    }
};