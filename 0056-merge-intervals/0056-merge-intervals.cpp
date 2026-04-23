class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end());
    int prev_start=intervals[0][0];
    int prev_end=intervals[0][1];
    vector<vector<int>>ans;
    for(int i=1;i<intervals.size();i++){
    if(prev_end>=intervals[i][0]){
    prev_end=max(prev_end,intervals[i][1]);    
    }
    else{
    vector<int>v={prev_start,prev_end};
    ans.push_back(v);
    prev_start=intervals[i][0];
    prev_end=intervals[i][1];
    }    
    }
    vector<int>v={prev_start,prev_end};
    ans.push_back(v);
    return ans;    
    }
};