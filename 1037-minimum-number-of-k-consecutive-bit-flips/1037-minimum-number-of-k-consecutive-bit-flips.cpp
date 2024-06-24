// class Solution {
// public:
//     int minKBitFlips(vector<int>& nums, int k) {
//         int count = 0;
//         for (int i = 0; i <= nums.size() - k; ++i) {
//             if (nums[i] == 0) {
//                 for (int j = i; j < i + k; ++j) {
//                     nums[j] = 1 - nums[j];
//                 }
//                 count++;
//             }
//         }
//         for (int i = 0; i < nums.size(); ++i) {
//             if (nums[i] == 0) {
//                 return -1;
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flipped = 0;
        int res = 0;
        vector<int> isFlipped(n, 0);

        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                flipped ^= isFlipped[i - k];
            }
            if (flipped == nums[i]) {
                if (i + k > n) {
                    return -1;
                }
                isFlipped[i] = 1;
                flipped ^= 1;
                res++;
            }
        }

        return res;
    }
};

