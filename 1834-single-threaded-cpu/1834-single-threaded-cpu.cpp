class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
    vector<int>result;
    int i=0;
    for(int i=0;i<tasks.size();i++) tasks[i].push_back(i);
    sort(tasks.begin(),tasks.end(),[](auto &a,auto &b){
    if (a[0] == b[0])
        return a[1] < b[1];

    return a[0] < b[0];    
    });
    int start=tasks[0][0];
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    while(i<tasks.size()){
    while(i<tasks.size() && tasks[i][0]<=start){
    pq.push({tasks[i][1],tasks[i][2]});
    i++;    
    }
    if(pq.empty() && i<tasks.size()) start=tasks[i][0];
    else{
    auto [time,index]=pq.top();
    start+=time;
    pq.pop();
    result.push_back(index);    
    }    
    }
    while(!pq.empty()){
    auto [time,index]=pq.top();
    result.push_back(index);
    pq.pop();    
    }
    return result;    
    }
};