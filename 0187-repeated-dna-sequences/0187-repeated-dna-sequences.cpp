class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if(s.size()<10){
            return {};
        }
        map<string,int> mp;
        for(int i=0;i<=s.size()-10;i++){
            string x=s.substr(i,10);
            mp[x]++;
        }
        for(auto it:mp){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }
        return ans;
        
    }
};