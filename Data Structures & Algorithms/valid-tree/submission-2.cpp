class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1)
            return false;
    unordered_map<int, vector<int>> adjList;

        // undirected so can go both ways
        for (auto edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<bool>visited(n, false);

        queue<int> q;
        q.push(0);
        visited[0] = true;

        int count = 0;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            count++;

            for (auto neigh : adjList[node]) {
                if (!visited[neigh]) {
                    visited[neigh] = true;
                    q.push(neigh);
                }
            }

        }

        return count == n;
    
    }
};
