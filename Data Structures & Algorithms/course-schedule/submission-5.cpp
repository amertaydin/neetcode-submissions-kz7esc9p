
class Solution {
unordered_map<int, vector<int>>adjList;
unordered_map<int, int> dependency;
unordered_set<int> visited;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;

        for (auto preq : prerequisites) {
            adjList[preq[1]].push_back(preq[0]); // take course first, then you are able to take second
            dependency[preq[0]]++; // course 0 depending on course 1
        }

        for (int i = 0; i < numCourses; i++) {
            if (dependency[i] == 0) {
                q.push(i);
            }
        }

        int finish = 0;
        while(!q.empty()) {
            auto lesson = q.front();
            q.pop();
            finish++;

            for (auto neighbor : adjList[lesson]) {
                dependency[neighbor]--;
                if (dependency[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        return finish == numCourses;
    }
};
