class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for(int i=0;i<matrix.size();i++){
    int low=0;
    int high=matrix[i].size()-1;
    while(low<=high){
    int mid=(low+high)>>1;
    if(matrix[i][mid]==target) return true;
    else if(matrix[i][mid]>target) high=mid-1;
    else low=mid+1;
    }    
    }
    return false;    
    }
};