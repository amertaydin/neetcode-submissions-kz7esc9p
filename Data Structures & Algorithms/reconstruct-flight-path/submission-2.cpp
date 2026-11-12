class Solution {
        unordered_map<string, priority_queue<string, vector<string>, greater<>>> graph;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> result;

        // create adjcacenyList
        for (auto ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }

        dfs("JFK", result);
        reverse(result.begin(), result.end());
        return result;

    }

    void dfs(string src, vector<string>&result) {
        // get the priority_queue
        auto &pq = graph[src];
        
        while(!pq.empty()) {
            string next = pq.top();
            pq.pop();
            dfs(next, result);
        }

        result.push_back(src);
    }
};
