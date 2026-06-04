class Solution {
public:
    int findsubarrays(vector<int>&nums,int goal){
    if(goal<0) return 0;    
    int left=0;
    int right=0;
    int sum=0;
    int count=0;
    while(right<nums.size()){
    if(nums[right]%2!=0) sum++;
    while(left<=right && sum>goal){
    if(nums[left]%2!=0) sum--;
    left++;
    }
    if(sum<=goal) count=count+(right-left)+1;
    right++;    
    }
    return count;    
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
     int count_1=findsubarrays(nums,k);
    int count_2=findsubarrays(nums,k-1);
    return abs(count_1-count_2);        
    }
};