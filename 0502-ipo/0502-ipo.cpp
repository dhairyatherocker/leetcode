class Solution {
public:
    // int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    // int n=profits.size();
    // int total_capital=w;    
    // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    // for(int i=0;i<n;i++){
    // pq.push({capital[i],profits[i]});
    // }
    // while(!pq.empty() && k>0){
    // queue<pair<int,int>>q;
    // while(!pq.empty()){
    // int cap=pq.top().first;
    // int prof=pq.top().second;
    // if(cap<=w) break;
    // q.push({cap,prof});
    // pq.pop();    
    // }
    // if(pq.empty()) return total_capital;
    // auto [cap,prof]=pq.top();
    // pq.pop();
    // w=w+prof;
    // total_capital+=prof;
    // while(!q.empty()){
    // auto node=q.front();
    // pq.push({node.first,node.second});
    // q.pop();    
    // }
    // k--;                                                        
    // }
    //  return total_capital;   
    // }
    
int findMaximizedCapital(int k, int w,
                         vector<int>& profits,
                         vector<int>& capital) {

    int n = profits.size();

    // Min heap: {required capital, profit}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    // Max heap: affordable project profits
    priority_queue<int> maxProfit;

    for (int i = 0; i < n; i++) {
        pq.push({capital[i], profits[i]});
    }

    while (k > 0) {

        // Move all affordable projects to max heap
        while (!pq.empty() && pq.top().first <= w) {
            maxProfit.push(pq.top().second);
            pq.pop();
        }

        // No affordable project remains
        if (maxProfit.empty()) {
            break;
        }

        // Choose the maximum-profit affordable project
        w += maxProfit.top();
        maxProfit.pop();

        k--;
    }

    return w;
}

};