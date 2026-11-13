// I have to create an adjecency list
// also need to keep track of the best costs

class Solution {
    // src -> dst, cost
    unordered_map<int, vector<pair<int, int>>> adjList;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        // create the adjList
        for (auto flight : flights) {
            adjList[flight[0]].push_back({flight[1], flight[2]});
        }        

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;

        vector<int>bestStops(n, INT_MAX);

        // src, cost, stops
        pq.push({0, src, 0});

        while(!pq.empty()) {
            auto [cost, curr, stops] = pq.top();
            pq.pop();

            if (curr == dst) return cost;

            if (stops > k || bestStops[curr] < stops) continue;

            bestStops[curr] = stops;

            for (auto & [neighbor, price] : adjList[curr]) {
                pq.push({cost + price, neighbor, stops + 1});
            }
        }

        return -1;
    }
};
