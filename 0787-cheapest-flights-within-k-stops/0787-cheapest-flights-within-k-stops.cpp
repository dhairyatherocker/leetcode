class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int K) {

        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        // {stops, {node, cost}}
        queue<pair<int, pair<int,int>>> q;
        q.push({0, {src, 0}});

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while (!q.empty()) {
            auto [stops, p] = q.front();
            q.pop();

            int node = p.first;
            int cost = p.second;

            if (stops > K) continue;

            for (auto &it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;

                if (cost + wt < dist[adjNode]) {
                    dist[adjNode] = cost + wt;
                    q.push({stops + 1, {adjNode, cost + wt}});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};