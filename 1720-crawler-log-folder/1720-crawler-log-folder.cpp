class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;
        for(const string& it:logs){
            if(it!="../"){
                if(it!="./"){
                    st.push(it);
                }
            }
            if(it=="../"&&!st.empty()){
                st.pop();
            }
        }
        return st.size();
    }
};