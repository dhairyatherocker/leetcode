class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int>m;
    int max_len=0;
    int sum=0;
    m[0]=1;
    for(int i=0;i<nums.size();i++){
    sum+=nums[i];
    int rem=sum-k;
    if(m.find(rem)!=m.end()){
    max_len+=m[rem];
     }
 m[sum]++;
    }
    return max_len;   
    }
};