class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    reverse(matrix.begin(),matrix.end());
    vector<vector<int>>verify(matrix.size(),vector<int>(matrix[0].size(),0));
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
    if(verify[i][j]==0 && verify[j][i]==0 && i!=j){
    matrix[i][j]=matrix[i][j]^matrix[j][i];
    matrix[j][i]=matrix[i][j]^matrix[j][i];
    matrix[i][j]=matrix[i][j]^matrix[j][i];
    verify[i][j]=1;
    verify[j][i]=1;    
    }    
    }    
    }
    }
};