class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    intervals.push_back(newInterval);
    sort(intervals.begin(),intervals.end(),[](const auto &a,const auto &b){
    int d1=a[0];
    int d2=b[0];
    if(d1!=d2) return d1<d2;
    return a[1]<b[1];    
    });
    int prev_start=intervals[0][0];
    int prev_end=intervals[0][1];
    vector<vector<int>>ans;
    for(int i=1;i<intervals.size();i++){
    int cur_start=intervals[i][0];
    int cur_end=intervals[i][1];
    if(cur_start>prev_end){
    ans.push_back({prev_start,prev_end});
    prev_start=cur_start;
    prev_end=cur_end;    
    }
    else{
    prev_end=max(prev_end,cur_end);    
    }     
    }
    ans.push_back({prev_start,prev_end});
    return ans;    
    }
};