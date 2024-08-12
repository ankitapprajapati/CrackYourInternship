class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers;

        // ratio,quality
        for (int i = 0; i < n; i++) {
            double ratio = (double)wage[i] / quality[i];
            workers.push_back({ratio, quality[i]});
        }

        // Sort
        sort(workers.begin(), workers.end());

        priority_queue<int> pq;
        int qualitySum = 0;
        double minCost = numeric_limits<double>::max();

        for (const auto& worker : workers) {
            double ratio = worker.first;
            int q = worker.second;

            pq.push(q);
            qualitySum += q;

            if (pq.size() > k) {
                qualitySum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                double cost = qualitySum * ratio;
                minCost = min(minCost, cost);
            }
        }

        return minCost;
    }

};