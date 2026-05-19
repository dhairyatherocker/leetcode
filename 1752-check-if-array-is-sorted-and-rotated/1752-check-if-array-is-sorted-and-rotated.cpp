class Solution {
public:
    bool check(vector<int>& nums) {
    int start=0;
    int last=nums.size()-1;
    while(last>0 && nums[last]>=nums[last-1]) last--;
    while(start<nums.size()-1 && nums[start]<=nums[start+1]) start++;
    if(last==0 || start==nums.size()-1) return true;
    if(last-start==1 && nums[nums.size()-1]<=nums[0]) return true;
    return false;   
    }
};