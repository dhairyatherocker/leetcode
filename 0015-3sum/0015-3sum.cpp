class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    int n=nums.size();    
    sort(nums.begin(),nums.end());
    set<vector<int>>s;
    vector<vector<int>>ans;
    for(int i=0;i<nums.size();i++){
    int first=i+1;
    int last=nums.size()-1;
    while(first<last && first<nums.size() && last>=0 ){
    int sum=nums[i]+nums[first]+nums[last];
    if(sum==0){
    vector<int>v={nums[i],nums[first],nums[last]};
    sort(v.begin(),v.end());
    s.insert(v);
    first++;
    last--;
    }
    else if(sum>0){
    last--;
    }
    else{
    first++;
    }
    }
    }
    for(auto it : s) ans.push_back(it);
    return ans;    
    }
};