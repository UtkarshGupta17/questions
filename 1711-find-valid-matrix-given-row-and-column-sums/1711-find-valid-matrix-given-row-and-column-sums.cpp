class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(); 
        int m = colSum.size();  
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val=min(rowSum[i],colSum[j]);
                rowSum[i]=rowSum[i]-val;
                colSum[j]=colSum[j]-val;
                mat[i][j]=val;
            }
        }
        return mat;

    }
};