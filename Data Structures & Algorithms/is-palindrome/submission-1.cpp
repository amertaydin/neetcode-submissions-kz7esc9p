// what
// check if a string is a palindrome

// which pattern
// two pointers

// how
// start from left and right, if non alnum, skip

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;

        while (l <= r) {
            cout << "hey" << endl;
            if (!isalnum(s[l])) {
                l++;
                continue;
            }
            if (!isalnum(s[r])) {
                r--;
                continue;
            }
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            l++;
            r--;
        }
        return true;        
    }
};
