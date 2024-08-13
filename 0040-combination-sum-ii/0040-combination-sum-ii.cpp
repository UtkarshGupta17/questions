class Solution {
public:
    void func(int ind, int sum, vector<int> &arr, vector<vector<int>> &summ, vector<int> &ds) {
        if (sum == 0) {
            summ.push_back(ds);
            return;
        }
        for (int i = ind; i < arr.size(); i++) {
            // Skip duplicates
            if (i > ind && arr[i] == arr[i - 1]) continue;
            if (arr[i] > sum) break; // Optimization: stop if the element is greater than the remaining sum
            ds.push_back(arr[i]); // Choose the current candidate
            func(i + 1, sum - arr[i], arr, summ, ds); // Recur with remaining sum and next index
            //ind value increases as in function i+1 this is the ind only but the new ind value is i+1;
            
            ds.pop_back(); // Backtrack (un-choose the current candidate)
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        func(0, target, candidates, ans, ds);
        return ans;
    }
};
