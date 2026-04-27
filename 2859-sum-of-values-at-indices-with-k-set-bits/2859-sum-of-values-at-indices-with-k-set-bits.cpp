class Solution {
public:
    int numbits(int num){
    int count=0;
    while(num!=0){
    count+=(num&1);
    num=num>>1;    
    }
    return count;    
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
    int count=0;
    for(int i=0;i<nums.size();i++){
    if(numbits(i)==k) count+=nums[i];   
    } 
    return count;   
    }
};