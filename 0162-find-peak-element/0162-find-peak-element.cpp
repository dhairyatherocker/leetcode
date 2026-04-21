class Solution {
public:
    int findPeakElement(vector<int>& nums){
    int index=0;
    if(nums[nums.size()-1]>nums[0]){
    index=nums.size()-1; 
    }
    for(int i=1;i<nums.size()-1;i++){
    if(nums[i]>nums[i-1] && nums[i+1]<nums[i] && nums[index]<nums[i]) index=i;  
    }
    return index;    
    }
};