class Solution {
public:
    int largestnum(int index,vector<int>&nums){
    int largest=-1;
    for(int i=index+1;i<nums.size();i++){
    if(nums[i]>nums[index]){
    largest=nums[i];
    break;    
    }    
    }
    return largest;    
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
     vector<int>v;
     unordered_map<int,int>m;
     for(int i=0;i<nums2.size();i++){
     m[nums2[i]]=i;   
     }
     for(int i=0;i<nums1.size();i++){
     int index=m[nums1[i]];
     v.push_back(largestnum(index,nums2));
     } 
     return v;  
  
    }
};