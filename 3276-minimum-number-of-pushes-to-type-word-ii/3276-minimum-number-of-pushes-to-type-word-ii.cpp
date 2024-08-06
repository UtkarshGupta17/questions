class Solution {
public:
    int minimumPushes(string word) {
       vector<int> vt(26,0);
       for(auto& c : word){
            vt[c-'a']++;
       }
       sort(vt.begin(),vt.end(),greater<int>());
       int res = 0;
       for(int i = 0 ; i < 26 ; i++){
        int freq = vt[i];
        int press = (i/8) + 1;
        res += (freq * press);
       }
       return res;
    }
};