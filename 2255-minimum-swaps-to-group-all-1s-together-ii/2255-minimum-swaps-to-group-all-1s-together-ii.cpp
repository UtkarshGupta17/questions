class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                count++;
            }
        }
        if (count == 0 || count == 1) {
            return 0;
        }
        
        int maxi = 0;
        int count2 = 0;
        
        for (int i = 0; i < count; i++) {
            if (nums[i] == 1) {
                count2++;
            }
        }
        maxi = count2;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] == 1) {
                count2--;
            }
            if (nums[(i + count - 1) % n] == 1) {
                count2++;
            }
            maxi = max(maxi, count2);
        }
        
        return count - maxi;
    }
};

// //TLE - 49/63 testcase passed 
// class Solution {
// public:
//     int minSwaps(vector<int>& nums) {
//         int count=0;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==1){
//                 count++;
//             }
//         }
//         if (count == 0 || count == 1) {
//             return 0;
//         }
//         cout<<count;
//         int maxi=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             int count2=0;
//             for(int j=i;j<i+count;j++)
//             {
//                 if (nums[j % nums.size()] == 1) {
//                     count2++;
//                 }
//             }
//             maxi=max(maxi,count2);
//         }
//         cout<<maxi;
//         return count-maxi;
//     }
// };