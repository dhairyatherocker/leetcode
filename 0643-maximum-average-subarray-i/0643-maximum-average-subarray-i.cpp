class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
    double sum=nums[0];
    double ans=INT_MIN;
    int i=0;
    int j=0;
    while(i<nums.size() && j<nums.size()){
    while(j<nums.size()-1 && (j-i+1)<k){
    j++;
    sum+=nums[j];    
    }
    if(j>=nums.size()) break;
    else if(j-i+1==k) ans=max(sum/k,ans);
   
    if(i<nums.size()) sum-=nums[i];
    i++; 
    }
    return ans;    
    }
};