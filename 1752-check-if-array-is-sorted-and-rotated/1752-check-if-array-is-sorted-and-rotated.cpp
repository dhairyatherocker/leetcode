class Solution {
public:
    bool check(vector<int>& nums) {
    int end=nums.size()-1;
    int n=nums.size()-1;
    while(end>0 && nums[end-1]<=nums[end]) end--;
    if(end==0) return true;
    int start=0;
    if(nums[start]<nums[n]) return false;
    while(start<end && nums[start+1]>=nums[start]) start++;
    if(start+1==end) return true;
    return false; 
    }
};