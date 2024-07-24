class Solution {
public:
    int func(int x, vector<int>& mapping) {
        string str = to_string(x);
        int ans = 0;
        for (int i = 0; i < str.size(); i++) {
            ans = ans * 10 + mapping[str[i] - '0'];
        }
        return ans;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<pair<int, int>, int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            int x = func(nums[i], mapping);
            ans.push_back({{x, i}, nums[i]});
        }
        sort(ans.begin(), ans.end());

        vector<int> result;
        for (int i = 0; i < ans.size(); i++) {
            result.push_back(ans[i].second);
        }

        return result;
    }
};
