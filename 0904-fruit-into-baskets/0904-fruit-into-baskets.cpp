class Solution {
public:
    int totalFruit(vector<int>& nums) {
    unordered_map<int,int>m;
    int i=0;
    int j=0;
    int maxlen=0;
    while(j<nums.size()){
    if(m.find(nums[j])!=m.end()){
    maxlen=max(maxlen,j-i+1);
    m[nums[j]]++;
    j++;    
    }
    else if(m.find(nums[j])==m.end() && m.size()<2){
    m[nums[j]]=1;
     maxlen=max(maxlen,j-i+1);
    j++;
    }
    else{
    while(i<=j && m.size()==2){
    m[nums[i]]--;
    if(m[nums[i]]==0) m.erase(nums[i]);
    i++;
    }
    if(m.size()<2) m[nums[j]]=1;
    maxlen=max(maxlen,j-i+1);
    j++;    
    } 
    }
    return maxlen;    
    }
};