// what it wants
// check if we can form a valid string
// * count as joker or and empty string

// what kind of pattern can I use
// two pointer?

// start from start and end go inwards


class Solution {
public:
    bool checkValidString(string s) {

        stack<char> left;
        stack<char> stars;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')') {
                if (!left.empty()) {
                    left.pop();
                } else if (!stars.empty()) {
                    stars.pop();
                } else {
                    return false;
                }
            } else if (s[i] == '(') {
                left.push(i);
            } else if (s[i] == '*') {
                stars.push(i);
            }
        }

        while (!left.empty() && !stars.empty()) {
            if (left.top() > stars.top()) return false;
            left.pop();
            stars.pop();
        }

        if (left.size() > stars.size()) return false;

        return true;

    }
    
};
