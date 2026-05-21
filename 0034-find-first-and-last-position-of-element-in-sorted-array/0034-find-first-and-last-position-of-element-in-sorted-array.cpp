class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
     int low=0;
     int high=nums.size()-1;
     vector<int>v(2,-1);
     while(low<=high){
     int mid=(low+high)>>1;
     if(nums[mid]<=target) low=mid+1;
     else high=mid-1;   
     }
     if(high>=0 &&  nums[high]==target) v[1]=high;
     low=0;
     high=nums.size()-1;
     while(low<=high){
     int mid=(low+high)>>1;
     if(nums[mid]>=target) high=mid-1;
     else low=mid+1;   
     }
     if(low<nums.size() && nums[low]==target) v[0]=low;

     return v;    
    }
};