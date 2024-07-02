class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        vector<int> arr;
        for(int it:nums1){
            mp[it]++;
        }
        for(int it:nums2){
            if(mp[it]>0){
                arr.push_back(it);
                mp[it]--;
            }
        }
        return arr;
    }
};