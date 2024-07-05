class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int mat[matrix.size()][matrix[0].size()];
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                mat[i][j]=matrix[j][i];
            }
        }
        int temp;
        int n=matrix.size();
        

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                matrix[i][j]=mat[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
        

        
    }
};