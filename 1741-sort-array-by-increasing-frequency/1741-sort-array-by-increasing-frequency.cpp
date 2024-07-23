class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> mp;
        for (int it : nums) {
            mp[it]++;
        }
        vector<int> ans(nums);
        sort(ans.begin(), ans.end(), [&mp](int a, int b) {
            if (mp[a] == mp[b]) {
                return a > b; 
            }
            return mp[a] < mp[b]; 
        });

        return ans;
        
    }
};