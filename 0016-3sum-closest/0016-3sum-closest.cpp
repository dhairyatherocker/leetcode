class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    int n=nums.size();    
    sort(nums.begin(),nums.end());
    long long maxsum=nums[n-1]+nums[n-2]+nums[n-3];
    for(int i=0;i<nums.size();i++){
    int first=i+1;
    int last=nums.size()-1;
    while(first<last && first<nums.size() && last>=0 ){
    int sum=nums[i]+nums[first]+nums[last];
    if(sum==target){
    maxsum=target; 
    first++;
    last--;
    }
    else if(sum>target){
    if(abs(sum-target)<abs(maxsum-target)) maxsum=sum;     
    last--;
    }
    else{
    if(abs(sum-target)<abs(maxsum-target)) maxsum=sum;  
    first++;
    }
    }
    }
    return maxsum;    
    }
};