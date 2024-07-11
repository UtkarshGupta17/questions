class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(s[i]==')'){
                string rev="";
                while(st.top()!='('&&!st.empty()){
                    rev=rev+st.top();
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
                for(int j=0;j<rev.size();j++){
                    st.push(rev[j]);
                }
            }
            else{
                st.push(c);
            }
        }

        string ans="";
        while(!st.empty()){
            ans=ans+st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;
        
    }
};