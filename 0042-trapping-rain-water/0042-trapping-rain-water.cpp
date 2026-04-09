class Solution {
public:
    int trap(vector<int>& height) {
    int n=height.size();    
    vector<int>prefix(n);
    vector<int>suffix(n);
    int maxi=height[0];
    for(int i=0;i<n;i++){
    maxi=max(height[i],maxi);
    prefix[i]=maxi;
    }
    maxi=height[n-1];
    for(int i=n-1;i>=0;i--){
    maxi=max(height[i],maxi);
    suffix[i]=maxi;
    }
    int total_water=0;
    for(int i=0;i<n;i++){
    total_water=total_water+min(suffix[i],prefix[i])-height[i];    
    } 
    return total_water;    
    }
};