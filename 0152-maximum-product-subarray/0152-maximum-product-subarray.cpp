class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int maxi=INT_MIN;
    // if(nums.size()==1) return nums[0];
    for(int i=0;i<nums.size();i++){
    int mult=nums[i]; 
      maxi=max(mult,maxi);     
    for(int j=i+1;j<nums.size();j++){
    mult=mult*nums[j];
    maxi=max(mult,maxi);   
    }    
    }
    return maxi; 
    // int maxi=INT_MIN;
    // int mult=1;
    // for(int i=0;i<nums.size();i++){
    // mult*=nums[i];
    // maxi=max(maxi,mult);
    // if(mult<0) mult=1;
    // }
    // return maxi;   
    }
};