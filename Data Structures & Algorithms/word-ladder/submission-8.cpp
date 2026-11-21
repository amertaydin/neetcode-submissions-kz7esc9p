class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>words(wordList.begin(), wordList.end());
        unordered_set<string>visited;
        queue<pair<string, int>> q; // word, step
        unordered_map<string, vector<string>> adjList;

        // check if endWord is even in the list
        if(!words.count(endWord)) return false;

        // create adjacency matrix        
        for (auto word : wordList) {
            for (int i = 0; i < word.size(); i++) {
                string pattern = word;
                pattern[i] = '*';
                adjList[pattern].push_back(word);
            }
        }

        q.push({beginWord, 1});
        visited.insert(beginWord);

        while(!q.empty()) {
            auto [word, step] = q.front();
            q.pop();

            if (word == endWord) return step;

            for (int i = 0; i < word.size(); i++) {
                string pattern = word;
                pattern[i] = '*';

                for (auto curr : adjList[pattern]) {
                    if (!visited.count(curr)) {
                        visited.insert(curr);
                        q.push({curr, step + 1});
                    }
                }

                adjList[pattern].clear();
            }
        }

        return 0;

    }
};
