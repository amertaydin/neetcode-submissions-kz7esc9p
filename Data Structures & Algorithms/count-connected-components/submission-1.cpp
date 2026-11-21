class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjList;
        vector<bool>visited(n, false);
        int components = 0;
        queue<int> q;

        for (auto edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;
            
            // we need to count components
            components++;

            // insert into the queue beginning of the first
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                auto curr = q.front();
                q.pop();

                for (auto neigh : adjList[curr]) {
                    if (!visited[neigh]) {
                        visited[neigh] = true;
                        q.push(neigh);
                    }
                }
            }
        }
        return components;   

    }
};
