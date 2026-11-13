// ı need to create and adjList for every char
// and then I need compare same strings and last char different
// and if same string but with different prefix, cannot come later 

class Solution {
    unordered_map<char, unordered_set<char>> adjList;
    string result;
    unordered_map<char, bool> visited;
public:
    string foreignDictionary(vector<string>& words) {
        
        for (auto word : words) {
            for (char c : word) {
                adjList[c];
            }
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string str1 = words[i];
            string str2 = words[i+1];

            // compare the strings
            int minLen = min(str1.size(), str2.size());
            if (str1.length() > str2.length() && str1.substr(0, minLen)==str2.substr(0, minLen))
            return "";
        

        for (int i = 0; i < minLen; i++) {
            if (str1[i] != str2[i]) {
                adjList[str1[i]].insert(str2[i]);
                break;
            }
        }
        }
        // if there's a cycle, invalid
        for(auto pairs : adjList) {
            if (dfs(pairs.first))
                return "";
        }

        reverse(result.begin(), result.end());
        return result;
    }

    bool dfs(char ch) {
        if (visited.find(ch) != visited.end()) {
            return visited[ch];
        }
        visited[ch] = true;

        for (auto neighbor : adjList[ch]) {
            if (dfs(neighbor)) {
                return true;
            }
        }

        visited[ch] = false;
        result.push_back(ch);
        return false;
    }
};
