class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1, st2;

        for (char it : s) {
            if (it != '#') {
                st1.push(it);
            } else if (!st1.empty()) {
                st1.pop();
            }
        }

        for (char it : t) {
            if (it != '#') {
                st2.push(it);
            } else if (!st2.empty()) {
                st2.pop();
            }
        }

        if (st1.size() != st2.size()) {
            return false;
        }
        
        while (!st1.empty()) {
            if (st1.top() != st2.top()) {
                return false;
            }
            st1.pop();
            st2.pop();
        }
        
        return true;
    }
};
