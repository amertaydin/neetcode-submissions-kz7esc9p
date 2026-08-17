// what
// find the length of longest substring without repeating characters

// which pattern
// sliding window

// how 
// have one set for chars, if duplicate, drop until we reset the state


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int maxLen = 0;
        unordered_set<char> seen;

        while (r < s.size()) {
            if (!seen.count(s[r])) {
                seen.insert(s[r]);
                r++;
                maxLen = maxLen > (r - l) ? maxLen : (r - l);
            } else {
                while(seen.count(s[r]) != 0) {
                    seen.erase(s[l]);
                    l++;
                }
            }
        }

        return maxLen;        
    }
};
