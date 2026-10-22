class Solution {
public:
    int findsubarrays(vector<int>&nums,int value){
    int i=0;
    int j=0;
    int count=0;
    unordered_map<int,int>m;
    while(j<nums.size()){
    m[nums[j]]++;
    while(i<=j && m.size()>value){
    m[nums[i]]--;
    if(m[nums[i]]==0) m.erase(nums[i]);
    i++;
    }
    count=count+j-i+1;
    j++;
    }
    return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
    return findsubarrays(nums,k)-findsubarrays(nums,k-1);    
    }
};