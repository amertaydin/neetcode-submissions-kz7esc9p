// what
// check if both strings have the exact same characters

// which pattern
// could use a map or char arr

// how
// 1- sort and compare
// loop through arr, increase for the first one and decrease for the second one

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        char arr[26];
        for (int i = 0; i < s.length(); i++) {
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (arr[i] != 0) return false;
        }
        return true;
    }
};
