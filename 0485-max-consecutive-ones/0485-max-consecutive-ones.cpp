class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    int count_1=0;
    int maxi=0;
    for(int i=0;i<nums.size();i++){
    if(nums[i]==1) count_1++;
    else{
    count_1=0;    
    }
    maxi=max(maxi,count_1);    
    }
    return maxi;    
    }
};