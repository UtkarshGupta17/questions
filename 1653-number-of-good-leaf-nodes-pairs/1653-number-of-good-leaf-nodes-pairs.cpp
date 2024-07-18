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
int pairs;

vector<int>dfs(TreeNode* root,int d){
    if(root==NULL){
        return {};
    }
    if(root->left==NULL && root->right==NULL){
        return {1};
    }
    vector<int> leftv = dfs(root->left,d);
    vector<int> rightv = dfs(root->right,d);
    for(auto lv : leftv){
            for(auto rv : rightv){
                if(lv + rv <= d) pairs++;
            }
        }
        vector<int> parentv;
        for(auto lv : leftv){
            if(lv + 1 < d) parentv.push_back(lv+1);
        }
        for(auto rv : rightv){
            if(rv + 1 < d) parentv.push_back(rv+1);
        }
        return parentv;    
}
    int countPairs(TreeNode* root, int distance) {
       pairs = 0;
        dfs(root,distance);
        return pairs;
    }
};