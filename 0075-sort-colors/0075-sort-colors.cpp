class Solution {
public:
    void sortColors(vector<int>& nums) {
    int first=0;
    int last=nums.size()-1;
    int mover=first;
    while(last>=0 && nums[last]==2) last--;
    while(mover<=last){
    if(nums[mover]==0){
    swap(nums[first],nums[mover]);
    first++;
    mover++;
    }
    else if(nums[mover]==2){
    swap(nums[mover],nums[last]);
    last--;    
    }
    else mover++;
    }    
    }
};