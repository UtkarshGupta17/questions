class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
    int minVal = *min_element(nums.begin(), nums.end());
    int maxVal = *max_element(nums.begin(), nums.end());
    int range = maxVal - minVal + 1;
    vector<int> count(range, 0);

    for (int num : nums) {
        count[num - minVal]++;
    }

    vector<int> sortedArray;
    for (int i = 0; i < range; ++i) {
        while (count[i] > 0) {
            sortedArray.push_back(i + minVal);
            count[i]--;
        }
    }
    
    return sortedArray;
        
    }
};