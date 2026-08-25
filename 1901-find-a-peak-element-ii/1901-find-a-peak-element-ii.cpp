class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
    for(int i=0;i<mat.size();i++){
    int low=0;
    int high=mat[i].size()-1;
    while(low<=high){
    int mid=(low+high)>>1;
    bool left=mid==0?true:false;
    bool right=mid==mat[i].size()-1?true:false;
    bool top=i==0?true:false;
    bool bottom=i==mat.size()-1?true:false;
    if(i>0 && mat[i-1][mid]<mat[i][mid]) top=true;
    if(i<mat.size()-1 && mat[i+1][mid]<mat[i][mid]) bottom=true;
    if(mid<mat[i].size()-1&& mat[i][mid+1]<mat[i][mid]) right=true;
    if(mid>0 && mat[i][mid-1]<mat[i][mid]) left=true;
    if(bottom && top && left && right) return {i,mid};
    else if(!left && !right){
    if(mat[i][mid-1]>mat[i][mid+1]) high=mid-1;
    else low=mid+1;     
    }
    else if(!left) high=mid-1;
    else low=mid+1;   
    }   
    }
    return {-1,-1};    
    }
};