// what
// I need to put strings who has the same anagram together

// which pattern
// I can use a map for this

// how
// 1-) sort them, if their sorted string equals to the key then add it
// 2-) while traversing add it to the result vector

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        vector<vector<string>> result;

        for (auto & str : strs) {
            string keyword = str;
            sort(str.begin(), str.end());
            anagrams[str].push_back(keyword);
        }

        for (auto & itr : anagrams) {
            result.push_back(itr.second);
        }

        return result;
    }
};
