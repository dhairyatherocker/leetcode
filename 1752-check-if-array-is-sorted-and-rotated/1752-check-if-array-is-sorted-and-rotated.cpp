class Solution {
public:
    bool check(vector<int>& nums) {
    // int end=nums.size()-1;
    // int n=nums.size()-1;
    // while(end>0 && nums[end-1]<=nums[end]) end--;
    // if(end==0) return true;
    // int start=0;
    // if(nums[start]<nums[n]) return false;
    // while(start<end && nums[start+1]>=nums[start]) start++;
    // if(start+1==end) return true;
    // return false; 

    int n=nums.size()-1;
    int end=n;
    while(end>0 && nums[end-1]<=nums[end]) end--;
    vector<int>dup=nums;
    sort(dup.begin(),dup.end());
    int start=0;
    reverse(nums.begin()+end,nums.end());
    reverse(nums.begin(),nums.begin()+end);
    reverse(nums.begin(),nums.end());
    if(dup==nums) return true;
    return false;
    }
};