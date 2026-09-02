class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
    int total_odd=0;
    int total_even=0;
    for(int i=0;i<nums1.size();i++){
     if(nums1[i]%2==0) total_even++;
     else total_odd++;   
    }
    bool ans=true;    
    for(int i=0;i<nums1.size();i++){
    if(nums1[i]%2!=0 && total_odd-1<=0) ans=false;     
    }
    if(ans) return true;
    ans=true; 
    for(int i=0;i<nums1.size();i++){
    if(nums1[i]%2==0 && total_odd<=0) ans=false;     
    }
    if(ans) return true;   
    return false;    
    }
};