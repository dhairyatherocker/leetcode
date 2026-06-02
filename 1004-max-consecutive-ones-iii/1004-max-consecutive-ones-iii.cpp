class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    int i=0;
    int j=0;
    int max_len=0;
    int chances=k;
    queue<int>q;
    while(j<nums.size()){
    if(nums[j]==1) max_len=max(max_len,j-i+1);
    else{
    if(chances>0){
    q.push(j);
    chances--;
    max_len=max(max_len,j-i+1);     
    }
    else if(chances<=0 && !q.empty()){
    int index=q.front();
    q.pop();
    i=index+1;
    max_len=max(max_len,j-i+1);
    q.push(j);
    }
    else if(chances<=0 && q.empty()){
    while(j<nums.size() && nums[j]!=1) j++;
    if(j<nums.size()){
    i=j;
    max_len=max(max_len,j-i+1);}
    }    
    }
    j++;    
    }
    return max_len;    
    }
};