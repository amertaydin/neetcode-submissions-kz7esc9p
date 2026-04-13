class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adjList; // src, dst, cost

        for (auto &flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int c = flight[2];

            adjList[u].push_back({v, c});
        }

        // minheap with cost, dst, stops
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;

        pq.push({0, src, 0});
        vector<int> bestStops(n, INT_MAX);

        while (!pq.empty()) {
            auto [cost, curr, stops] = pq.top();
            pq.pop();

            if (curr == dst) return cost;

            if (stops > k || stops > bestStops[curr]) continue;
            bestStops[curr] = stops;

            for (auto &[neig, price] : adjList[curr]) {
                pq.push({cost + price, neig, stops + 1});
            }
        }

        return -1;
    }
};
