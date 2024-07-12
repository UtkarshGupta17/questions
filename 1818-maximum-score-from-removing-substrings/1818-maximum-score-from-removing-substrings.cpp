class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int score = 0;
        string temp;
        if (x > y) {
            for (char c : s) {
                if (!temp.empty() && temp.back() == 'a' && c == 'b') {
                    temp.pop_back();
                    score += x;
                } else {
                    temp.push_back(c);
                }
            }
            
            s = temp;
            temp.clear();
            for (char c : s) {
                if (!temp.empty() && temp.back() == 'b' && c == 'a') {
                    temp.pop_back();
                    score += y;
                } else {
                    temp.push_back(c);
                }
            }
        } else {
            
            for (char c : s) {
                if (!temp.empty() && temp.back() == 'b' && c == 'a') {
                    temp.pop_back();
                    score += y;
                } else {
                    temp.push_back(c);
                }
            }
            
            s = temp;
            temp.clear();
            for (char c : s) {
                if (!temp.empty() && temp.back() == 'a' && c == 'b') {
                    temp.pop_back();
                    score += x;
                } else {
                    temp.push_back(c);
                }
            }
        }
        
        return score;
    }
};
