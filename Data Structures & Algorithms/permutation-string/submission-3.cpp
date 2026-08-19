// what
// check if a permutation of a string exists in other string
// abc, acb, cba, ...

// how, what's a valid window
// size needs to be equal to the s1
// we need total 3 for example, we add it to the frequency, and add it to the need
// if need is 0 we found it, if not we shrink the window

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = 0;
        int r = 0;
        unordered_map<char, int> freq;

        for (char s : s1) {
            freq[s]++;
        }

        int need = s1.size();

        // check if the frequency is equal to when we have the desired size
        while (r < s2.size()) {
            if (freq[s2[r]] > 0) {
                need--; // It shows how many chars are needed
            }
            freq[s2[r]]--; // we decrease the current freq
            r++; // move one char

            while (r - l > s1.size()) {
                freq[s2[l]]++;

                if (freq[s2[l]] > 0) {
                    need++;
                }

                l++;
            }


            if (need == 0) return true;
        }

        return false;
    }
};
