class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    int low=0;
    int high=nums.size()-1;
    while(low<=high){
    int mid=(low+high)>>1;
    bool left=true;
    bool right=true;
    if(mid>0 && nums[mid-1]>nums[mid]) left=false;
    if(mid<nums.size()-1 && nums[mid+1]>nums[mid]) right=false;
    if(left && right) return mid;
    else if(!right) low=mid+1;
    else high=mid-1;    
    }
    return -1;    
    }
};