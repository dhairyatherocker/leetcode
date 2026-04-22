class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    int product_s=1;
    int product_p=1;
    vector<int>prefix(nums.size(),-1);
    vector<int>suffix(nums.size(),-1);
    for(int i=0;i<nums.size();i++){
    prefix[i]=product_p;
    product_p*=nums[i];
    }
    for(int i=nums.size()-1;i>=0;i--){
    suffix[i]=product_s;
    product_s*=nums[i];
    }
    for(int i=0;i<nums.size();i++) nums[i]=prefix[i]*suffix[i];
    return nums;   
    }
};