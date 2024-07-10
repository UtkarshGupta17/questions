class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        vector<pair<int, int>> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = {reward1[i] - reward2[i], i};
        }
        sort(diff.begin(), diff.end(), greater<pair<int, int>>());

        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += reward1[diff[i].second];
        }
        for (int i = k; i < n; ++i) {
            sum += reward2[diff[i].second];
        }

        return sum;
    }
};
