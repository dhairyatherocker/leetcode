class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
    unordered_map<int,int>m;
    for(auto it : nums) m[it]=1;
    vector<int>result;
    for(int i=1;i<=nums.size();i++){
    if(m.find(i)==m.end()) result.push_back(i);    
    }
    return  result;    
    }
};