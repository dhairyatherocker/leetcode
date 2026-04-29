class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
    int area=0;
    double diagonal=0;
    for(int i=0;i<dimensions.size();i++){
    int length=dimensions[i][0];
    int breadth=dimensions[i][1];    
    double diag=sqrt(length*length + breadth*breadth);
    if(diag>diagonal){
    diagonal=diag;
    area=length*breadth;    
    }
    else if(diag==diagonal){
    area=max(area,length*breadth);    
    }
    } 
    return area;   
    }
};