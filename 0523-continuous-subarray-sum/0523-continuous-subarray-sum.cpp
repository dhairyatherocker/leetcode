class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int,int>m;
    int j=0;
    int sum=0;
    while(j<nums.size()){
   
    sum+=nums[j];
    if(sum%k==0 && j+1>=2) return true;
    else if(sum%k!=0){
    int rem=sum%k;
    if(m.find(rem)!=m.end() && (j-m[rem])>=2 ) return true;
    else if(m.find(rem)==m.end()) m[rem]=j;    
    }
    j++;    
    }
    return false;    
    }
};