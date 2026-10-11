class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    int n = quality.size();

        // {wage / quality ratio, quality}
        vector<pair<double, int>> workers;

        for (int i = 0; i < n; i++) {
            double ratio = (double)wage[i] / quality[i];
            workers.push_back({ratio, quality[i]});
        }

        // Sort workers by increasing wage/quality ratio
        sort(workers.begin(), workers.end());

        // Max heap stores qualities
        priority_queue<int> pq;

        int totalQuality = 0;
        double minCost = DBL_MAX;

        for (auto [ratio, q] : workers) {

            // Include current worker
            pq.push(q);
            totalQuality += q;

            // Keep only k smallest qualities
            if (pq.size() > k) {
                totalQuality -= pq.top();
                pq.pop();
            }

            // Calculate cost when exactly k workers are selected
            if (pq.size() == k) {
                double cost = ratio * totalQuality;
                minCost = min(minCost, cost);
            }
        }

        return minCost;    
    }
};