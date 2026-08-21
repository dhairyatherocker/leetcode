class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    map<int,int>m;
    int count=0;
    int sum=0;
    m[0]=1;
    for(int i=0;i<nums.size();i++){
    sum+=nums[i];
    int rem=sum-k;
    if(m.find(rem)!=m.end()){
    count+=m[rem];
    }
    m[sum]++;

    }
    return count;    
    }
};