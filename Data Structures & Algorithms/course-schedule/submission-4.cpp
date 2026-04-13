class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList;
        unordered_map<int,int> indegree;

        for (auto & preq : prerequisites) {
            adjList[preq[0]].push_back(preq[1]);
            indegree[preq[1]]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int finish = 0;
        while (!q.empty()) {
            int lesson = q.front();
            q.pop();
            finish ++;

            for (int nei : adjList[lesson]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        return finish == numCourses;

    }
};
