// need to divide into substrings, order matters, and return the sizes of the substrings

// pattern
// sliding window, greedy

// plan
// count the frequencies, until the frequency is 0 add
// but also we will add new words and their frequencies

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> freqMap;
        vector<int> result;
        unordered_set<char> seen;
        string currentSubstr;

        for (char ch : s) {
            freqMap[ch]++;
        }

        //loop
        for (char ch : s) {
            currentSubstr.push_back(ch);
            seen.insert(ch);
            freqMap[ch]--;
            if (freqMap[ch] == 0) {
                seen.erase(ch);
            }
            if (seen.size() == 0) {
                result.push_back(currentSubstr.size());
                currentSubstr.clear();
            }
        }
        return result;
    }
};
