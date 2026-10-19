class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    int i=0;
    int j=1;
    int max_len=1;
    while(j<nums.size()){
    int prev_num=nums[j-1];
    int freq=j-i;
    long long demand=1LL *(nums[j]-prev_num)*freq;
    while(i<j && demand>k){
    int renew=prev_num-nums[i];
    k+=renew;
    i++;
    freq=j-i;
    demand=1LL *(nums[j]-prev_num)*freq;    
    }
    if(i==j){
    j++;    
    continue;    
    }
    else if(demand<=k){
    k-=demand;
    max_len=max(max_len,j-i+1);
    j++;    
    }  
    }
    return max_len;
    }
};