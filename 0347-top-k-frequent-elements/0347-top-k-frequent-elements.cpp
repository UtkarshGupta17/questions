class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int> ans;
        
        vector<pair<int,int>> arr(mp.begin(),mp.end());
        sort(arr.begin(),arr.end(),[](pair<int,int> a,pair<int,int> b){
            return a.second>b.second;
        });
        
        for(int i=0;i<k;i++){
            ans.push_back(arr[i].first);
            cout<<arr[i].second;
        }
        return ans;
        
        
    }
};