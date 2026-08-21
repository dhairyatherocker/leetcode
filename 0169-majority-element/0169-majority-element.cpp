class Solution {
public:
    int majorityElement(vector<int>& nums) {
    int div=(nums.size()/2+1);
    int form_num=0;
    for(int  i=0;i<=31;i++){
    int count_1=0;   
    for(int j=0;j<nums.size();j++){
    count_1=count_1+(1 & (nums[j]>>i));    
    }
    if((count_1/div)>0) form_num=(form_num | (1<<i));    
    }
    return form_num;    
    }
};