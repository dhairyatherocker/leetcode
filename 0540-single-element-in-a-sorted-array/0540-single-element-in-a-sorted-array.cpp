class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
    int low=0;
    int high=nums.size()-1;
    while(low<=high){
    int mid=(low+high)>>1;
    int left=0;
    int right=0;
    bool valid=true;
    if(mid>0 && nums[mid-1]==nums[mid]){
    left=mid-1;
    right=mid;
    valid=false;    
    }
    else if(mid<nums.size()-1 && nums[mid]==nums[mid+1]){
    left=mid;
    right=mid-1;
    valid=false;
    }
    if(valid) return nums[mid];
    if(left%2!=0) high=mid-1;
    else low=mid+1;
    }
    return -1;    
    }
};