class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> arr; 
        vector<int> arr2; 

        for (int i = 0; i < matrix.size(); i++) {
            int mini = INT_MAX;
            for (int j = 0; j < matrix[0].size(); j++) {
                mini = min(mini, matrix[i][j]);
            }
            arr.push_back(mini);
        }
        for (int j = 0; j < matrix[0].size(); j++) {
            int maxi = INT_MIN;
            for (int i = 0; i < matrix.size(); i++) {
                maxi = max(maxi, matrix[i][j]);
            }
            arr2.push_back(maxi);
        }

        vector<int> ans;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == arr[i] && matrix[i][j] == arr2[j]) {
                    ans.push_back(matrix[i][j]);
                }
            }
        }

        return ans;
    }
};
