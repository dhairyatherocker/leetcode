class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int i=0;
    int j=nums.size()-1;
    int pairs=0;
    while(i<j){
    if((nums[i]+nums[j])<target){
    pairs+=(j-i);
    i++;    
    }
    else if((nums[i]+nums[j])>=target) j--;    
    }
    return pairs;    
    }
};