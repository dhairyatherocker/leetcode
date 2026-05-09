class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int>ans;
    vector<int>indegree(numCourses,0); 
    vector<vector<int>>adj(numCourses);
    for(int i=0;i<prerequisites.size();i++){
    int first=prerequisites[i][0];
    int second=prerequisites[i][1];
    indegree[first]++;
    adj[first].push_back(second);
    adj[second].push_back(first);   
    }
    queue<int>q;
    for(int i=0;i<numCourses;i++){
    if(indegree[i]==0) q.push(i);    
    }
    while(!q.empty()){
    auto node=q.front();
    ans.push_back(node);
    q.pop();
    for(auto it  : adj[node]){
    indegree[it]--;
    if(indegree[it]==0) q.push(it);    
    }    
    }
    for(auto it : indegree){
    if(it>0) return {};    
    } 
    return ans;       
    }
};