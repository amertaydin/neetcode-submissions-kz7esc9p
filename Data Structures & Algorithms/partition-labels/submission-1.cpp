// amazing question, really like it

// I need to have a frequency map
// a seen set, where if its in current substr, when freq = 0, 
// remove from seen, and push to result
// clear currentSubstr

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        unordered_set<char> seen;
        unordered_map<char, int> freqMap;
        string currentSubstr;

        for (char c : s) {
            freqMap[c]++;
        }

        for (int i = 0; i < s.size(); i++) {
            seen.insert(s[i]);
            freqMap[s[i]]--;
            currentSubstr += s[i];

            if (freqMap[s[i]] == 0) seen.erase(s[i]);

            if (seen.size() == 0) {
                result.push_back(currentSubstr.size());
                currentSubstr.clear();
            } 
        }

        return result;
    }
};
