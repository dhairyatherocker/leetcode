class Solution {
public:
    int findTheWinner(int n, int k) {
    queue<int>q;
    queue<int>dump;
    for(int i=1;i<=n;i++) q.push(i);
    while(q.size()!=1 && !q.empty()){
    for(int i=1;i<k;i++){
    int node=q.front();
    q.pop();
    q.push(node);    
    }
    q.pop();
    
    
    }
    return q.front();    
    }
};