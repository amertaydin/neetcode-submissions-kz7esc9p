// really nice question again
// order matters for cases such as
// !!!!!! *( so we need to store indexes

// have one stack for left paranthesis
// one for the stars

// if we see a right parantheses, pop one from left, if not any pop from star, if not return false

// then we will have 

class Solution {
public:
    bool checkValidString(string s) {
        stack<char> leftP;
        stack<char> stars;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')') {
                if (!leftP.empty()) {
                    leftP.pop();
                } else if (!stars.empty()) {
                    stars.pop();
                } else {
                    return false;
                }
            } else if (s[i] == '(') {
                leftP.push(i);
            } else {
                stars.push(i);
            }
        }

        // here we check the order
        while(!leftP.empty() && !stars.empty()) {
            // case *( left has higher index tham star
            if (leftP.top() > stars.top()) return false;
            leftP.pop();
            stars.pop();
        }

        if (!leftP.empty()) {
            if (leftP.size() > stars.size()) return false;
        }

        return true;
    }
};
