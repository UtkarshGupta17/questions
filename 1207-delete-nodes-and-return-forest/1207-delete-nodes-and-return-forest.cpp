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
    TreeNode* func(TreeNode* root, unordered_set<int>& st, vector<TreeNode*>& ans) {
        if (!root) {
            return nullptr;
        }
        root->left = func(root->left, st, ans);
        root->right = func(root->right, st, ans);

        if (st.find(root->val) != st.end()) {
            if (root->left) {
                ans.push_back(root->left);
            }
            if (root->right){
                ans.push_back(root->right);
            } 
            delete root;
            return nullptr;
        }

        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st;
        for(int i=0;i<to_delete.size();i++){
            st.insert(to_delete[i]);
        }
        vector<TreeNode*> ans;
        if (func(root, st, ans)) {
            ans.push_back(root);
        }
        return ans;
    }
};
