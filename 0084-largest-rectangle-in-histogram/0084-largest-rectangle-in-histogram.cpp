class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
     int n=heights.size();   
     vector<int>nse(n);
     vector<int>pse(n);
     stack<int>s1;
     stack<int>s2;

    // nse

    for(int i=n-1;i>=0;i--){
    while(!s1.empty() && (heights[s1.top()]>=heights[i])) s1.pop();
    if(s1.empty()) nse[i]=n;
    else nse[i]=s1.top();
    s1.push(i);    
    }

    // pse 

    for(int i=0;i<n;i++){
    while(!s2.empty() && (heights[s2.top()]>=heights[i])) s2.pop();
    if(s2.empty()) pse[i]=-1;
    else pse[i]=s2.top();
    s2.push(i);    
    }
    
    int max_area=0;

    for(int i=0;i<n;i++){
    max_area=max(max_area,(nse[i]-pse[i]-1)*heights[i]);
    }
    return max_area;
    }
};