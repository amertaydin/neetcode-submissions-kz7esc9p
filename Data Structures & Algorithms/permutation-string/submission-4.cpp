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
        
        vector<int> s1Freq(26, 0);
        vector<int> windowFreq(26, 0);

        for (char s : s1) {
            s1Freq[s - 'a']++;
        }

        while (r < s2.size()) {
            windowFreq[s2[r] - 'a']++;

            while (r - l + 1 > s1.size()) {
                windowFreq[s2[l] - 'a']--;
                l++;
            }

            if (r - l + 1 == s1.size()) {
                if (windowFreq == s1Freq) return true;
            }

            r++;
        }

        return false;
    }
};
