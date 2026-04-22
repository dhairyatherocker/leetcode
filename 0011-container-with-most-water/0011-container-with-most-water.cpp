class Solution {
public:
    int maxArea(vector<int>& height) {
    int i=0;
    int j=height.size()-1;
    int max_water=0;
    while(i<j){
    int breadth=j-i;
    int length=min(height[i],height[j]);
    max_water=max(max_water,breadth*length);
    if(height[i]>height[j]) j--;
    else i++;    
    }
    return max_water;    
    }
};