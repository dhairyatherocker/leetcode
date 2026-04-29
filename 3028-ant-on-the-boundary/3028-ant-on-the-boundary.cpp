class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
    int count=0;
    int dis=0;
    for(int i=0;i<nums.size();i++){
    dis+=nums[i];
    if(dis==0) count++;    
    } 
    return count;   
    }
};