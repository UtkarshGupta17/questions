class Solution {
private:
int func(vector<int>& nums)
{
    
    int n=nums.size();
    if (n == 0) return 0;
    int prev=nums[0];
    int prev2=0;

    for(int i=1;i<n;i++){
        int take=nums[i];
        if(i>1){
            take=take+prev2;
        }

        int nottake=0+prev;

        int curr=max(take,nottake);
        prev2=prev;
        prev=curr;
    }
    return prev;
}
public:

    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> one;
        vector<int> two;
        for(int i=1;i<nums.size();i++){
            one.push_back(nums[i]);
        }
        for(int i=0;i<nums.size()-1;i++){
            two.push_back(nums[i]);
        }
        int a=func(one);
        int b=func(two);
        return max(a,b);
        
    }
};