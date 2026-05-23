class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
    int low=0;
    int high=nums.size()-1;
    while(low<=high){
    int mid=(low+high)>>1;
    bool valid=true;
    int left=0;
    int right=0;
    if(mid!=0){
    if(nums[mid-1]==nums[mid]){valid=false;
    left=mid-1;
    }
    else left=mid;    
    }
    if(mid<nums.size()-1){
    if(nums[mid+1]==nums[mid]){
    valid=false;
    right=nums.size()-1-mid-1;    
    }
    else right=nums.size()-1-mid;    
    }
    if(valid) return nums[mid];
    else if(left%2!=0) high=mid-1;
    else low=mid+1;    
    }
    return -1;   
    }
};