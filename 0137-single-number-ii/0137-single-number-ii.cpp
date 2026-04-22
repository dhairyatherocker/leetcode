class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int ans=0;
    for(int i=0;i<32;i++){
    long long count_1=0;
    int temp=1<<i;
    for(int j=0;j<nums.size();j++){
    count_1=count_1+(nums[j]&temp);
    }
    if(count_1%3!=0) ans=ans|temp;
    }
    return ans;    
    }
};