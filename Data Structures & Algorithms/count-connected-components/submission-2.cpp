// I need to add adjacency list, and it's an undirected map
// for every node i'll iterate, but the connected nodes will go the queue and get processd

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int components = 0;
        unordered_set<int> visited;
        queue<int> q;
        unordered_map<int, vector<int>>adjList;

        for (auto edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++) {
            if (visited.count(i)) continue;

            components++;

            q.push(i);
            visited.insert(i);

            while(!q.empty()) {
                auto curr = q.front();
                q.pop();

                for(auto neigh : adjList[curr]) {
                    if (!visited.count(neigh)) {
                        visited.insert(neigh);
                        q.push(neigh);
                    }
                }
            }
        }

        return components;
    }
};
