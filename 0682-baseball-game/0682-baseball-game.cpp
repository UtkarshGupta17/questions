class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        
        for(const string& it : operations) {
            if(it != "C" && it != "D" && it != "+") {
                int val = stoi(it);
                st.push(val);
            }
            else if(it == "C") {
                st.pop();
            }
            else if(it == "D") {
                int x = st.top();
                st.push(2 * x);
            }
            else if(it == "+") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.push(x);
                st.push(x + y);
            }
        }
        
        int sum = 0;
        while(!st.empty()) {
            sum += st.top();
            st.pop();
        }
        
        return sum;
    }
};
