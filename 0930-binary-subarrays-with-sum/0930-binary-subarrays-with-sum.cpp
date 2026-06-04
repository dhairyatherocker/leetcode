class Solution {
public:
    int findsubarrays(vector<int>&nums,int goal){
    if(goal<0) return 0;    
    int left=0;
    int right=0;
    int sum=0;
    int count=0;
    while(right<nums.size()){
    sum+=nums[right];
    while(left<=right && sum>goal){
    sum-=nums[left++];
    }
    if(sum<=goal) count=count+(right-left)+1;
    right++;    
    }
    return count;    
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
    int count_1=findsubarrays(nums,goal);
    int count_2=findsubarrays(nums,goal-1);
    return abs(count_1-count_2);    
    }
};