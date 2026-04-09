class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int>v(nums.size(),-1);
    int n=nums.size();
    stack<int>s;
    for(int i=n-2;i>=0;i--) s.push(nums[i]);
    for(int i=n-1;i>=0;i--){
    while(!s.empty() && s.top()<=nums[i] ) s.pop();
    if(s.empty()) v[i]=-1;
    else v[i]=s.top(); 
     s.push(nums[i]);       
    }
    return v;

    }
};