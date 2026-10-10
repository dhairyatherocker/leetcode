class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), [](auto a, auto b) {
    if (a[0] == b[0])
        return a[1] < b[1];

    return a[0] < b[0];
    });
    int total_ballons=1;
    int start=points[0][0];
    int end=points[0][1];
    for(int i=1;i<points.size();i++){
    if(points[i][0]>end){
    start=points[i][0];
    end=points[i][1];
    total_ballons++;    
    }
    else{
    start=max(start,points[i][0]);
    end=min(end,points[i][1]);    
    }
    }
    return total_ballons;
    }
};