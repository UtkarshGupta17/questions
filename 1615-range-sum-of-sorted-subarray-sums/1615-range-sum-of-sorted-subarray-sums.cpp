class Solution {
public:
    const int MOD = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>arr ; 
        for(int i = 0 ; i < n; i++){
            long long curr = 0 ;
            for(int j = i ; j < n ; j++){
                curr += (nums[j]);
                arr.push_back(curr) ;
            }

        }
        sort(arr.begin(),arr.end());

        int sum=0;

        for(int i=left-1;i<right;i++){
            sum =(sum +arr[i]) % MOD;
        }
        return sum;


        
    }
};