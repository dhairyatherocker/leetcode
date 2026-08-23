class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    // lower bound
    int ans=nums.size();
    int low=0;
    int high=nums.size()-1;
    while(low<=high){
    int mid=(low+high)>>1;
    if(nums[mid]>=target){
    ans=mid;
    high=mid-1;    
    }
    else low=mid+1;    
    }
    if(ans==nums.size() || nums[ans]!=target) return {-1,-1};

    // upper bound

    low=0;
    high=nums.size()-1;
    int ans2=nums.size();
    while(low<=high){
    int mid=(low+high)>>1;
    if(nums[mid]>target){
    ans2=mid;
    high=mid-1;    
    }
    else low=mid+1;    
    }
    return {ans,ans2-1};
    }
};