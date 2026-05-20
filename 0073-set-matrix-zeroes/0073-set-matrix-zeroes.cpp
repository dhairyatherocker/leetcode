class Solution {
public:
    void setmatrix(int row,int col,vector<vector<int>>&matrix){
    for(int i=0;i<matrix[row].size();i++){
    matrix[row][i]=0;    
    }
    for(int i=0;i<matrix.size();i++){
    matrix[i][col]=0;    
    }
    return;    
    }
    void setZeroes(vector<vector<int>>& matrix) {
    set<pair<int,int>>s;
    for(int i=0;i<matrix.size();i++){
    for(int j=0;j<matrix[i].size();j++){
    if(matrix[i][j]==0) s.insert({i,j}); 
    }    
    }
    for(auto it : s){
    int row=it.first;
    int col=it.second;
    setmatrix(row,col,matrix);    
    }    
    }
};