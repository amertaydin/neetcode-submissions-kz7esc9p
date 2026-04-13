class Solution {
private:
    vector<string> results;
    unordered_map<string, priority_queue<string, vector<string>, greater<>>> graph;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for (auto & ticket : tickets) {
            graph[ticket[0]].push(ticket[1]); // adjList
        }

        dfs("JFK");

        reverse(results.begin(), results.end());
        return results;
    }

    void dfs(string src) {
        auto &pq = graph[src];

        while (!pq.empty()) {
            auto next = pq.top();
            pq.pop();
            dfs(next);
        }

        results.push_back(src);
    }
};
