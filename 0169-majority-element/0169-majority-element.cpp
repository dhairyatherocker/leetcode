class Solution {
public:
    int majorityElement(vector<int>& nums) {
    unordered_map<int,int>m;
    for(int i=0;i<nums.size();i++){
    m[nums[i]]++;    
    }
    int max_num;
    int max_count=-1;
    for(auto it : m){
    if(max_count<it.second){
    max_count=it.second;
    max_num=it.first;    
    }
    }
    return max_num;    
    }
};