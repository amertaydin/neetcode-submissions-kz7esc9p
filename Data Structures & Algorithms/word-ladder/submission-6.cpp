class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> patternMap;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (!wordSet.count(endWord)) return 0;

        // create the pattern map
        for (auto & word : wordList) {
            for (int i = 0; i < word.size(); i++) {
                string pattern = word;
                pattern[i] = '*';
                patternMap[pattern].push_back(word);
            }
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1}); // find minimum number of words

        unordered_set<string> visited; // we will check if we seen this word
        visited.insert(beginWord);

        while(!q.empty()) {
            auto [word, step] = q.front();
            q.pop();

            //if (word == endWord) return step + 1;

            for (int i = 0; i < word.size(); i++) {
                string pattern = word;
                pattern[i] = '*';
                
                for (auto & neigh : patternMap[pattern]) {
                    if (neigh == endWord)
                        return step + 1;
                    if (!visited.count(neigh)) {
                        visited.insert(neigh);
                        q.push({neigh, step + 1});
                    }
                }

                patternMap[pattern].clear();
            }

        }
    return 0;
    }
};
