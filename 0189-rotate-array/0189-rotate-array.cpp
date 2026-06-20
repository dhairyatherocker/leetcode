class Solution {
public:
    void rotate(vector<int>& nums, int k) {
          k%=nums.size();
    int front_start=0;
    int last_start=nums.size()-k;
  
    vector<int>ans;
    for(int i=last_start;i<nums.size();i++) ans.push_back(nums[i]);
    for(int i=front_start;i<last_start;i++) ans.push_back(nums[i]);
    nums=ans;

    }
};