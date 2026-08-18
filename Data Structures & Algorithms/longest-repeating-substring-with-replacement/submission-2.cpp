class Solution {
public:
    int characterReplacement(string s, int k) {
       int l = 0;
       int r = 0;
       int maxFreq = 0;
       int result = 0;
       unordered_map<char, int> freqMap;

       while (r < s.size()) {
            freqMap[s[r]]++;
            maxFreq = max(maxFreq, freqMap[s[r]]);

            while((r - l + 1) - maxFreq > k) {
                freqMap[s[l]]--;
                l++;
            }

            result = max(result, (r-l+1));
            r++;
       }

       return result; 
    }
};
