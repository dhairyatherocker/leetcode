class Solution {
public:
    long long calculatehours(int pile,vector<int>&nums){
    long long hours=0;
    for(int i=0;i<nums.size();i++){
    hours+=(nums[i]/pile);
    if(nums[i]%pile!=0) hours++;    
    }
    return hours;    
    }
    int minEatingSpeed(vector<int>& piles, int h) {
    int  low=1;
    int  high=piles[0];
    for(int i=0;i<piles.size();i++){
    high=max(high,piles[i]);    
    }
    long long ans=INT_MAX;
    while(low<=high){
    long long mid=(low+high)>>1;
    long long result=calculatehours(mid,piles); 
    if(result<=h){
    ans=min(ans,mid);
    high=mid-1;    
    }
    else low=mid+1;   
    }
    return ans;
    }
};