/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_set<int> children;

        for(auto& arr:descriptions){
            int p=arr[0];
            int c=arr[1];
            int d=arr[2];
            children.insert(c);

            if(mp.find(p)==mp.end()){
                mp[p]=new TreeNode(p);
            }
            if(mp.find(c)==mp.end()){
                mp[c]=new TreeNode(c);
            }
            if(d==1){
                mp[p]->left=mp[c];
            }
            else{
                mp[p]->right=mp[c];
            }
        }
        int root=-1;
        for(auto& arr:descriptions){
            if(children.find(arr[0])==children.end()){
                root=arr[0];
                break;
            }
        }
        return mp[root];
    }
};