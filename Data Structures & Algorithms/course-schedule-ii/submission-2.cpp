class Solution {
    unordered_map<int, int> dependency;
    unordered_map<int, vector<int>> adjList;
    vector<int> result;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;

        for (auto preq : prerequisites) {
            dependency[preq[0]]++; // first one is dependent on other one
            adjList[preq[1]].push_back(preq[0]); // second one needs to be completed first
        }

        for (int i = 0; i < numCourses; i++) {
            if (dependency[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            auto lesson = q.front();
            q.pop();
            result.push_back(lesson);

            for (auto neighbor : adjList[lesson]) {
                // we just finished a course that neighbor was depending on
                dependency[neighbor]--;
                if (dependency[neighbor] == 0) {
                    q.push(neighbor);
                }
            }

        }
        
        if (result.size() == numCourses) {
            return result;
        } else {
            return {};
        }
            
    }
};
