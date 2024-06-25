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
TreeNode* func(TreeNode* root,int &sum){
    if(!root){
        return root;
    }
    if(root->right){
        func(root->right,sum);
    }
    sum=sum+root->val;
    root->val=sum;
    if(root->left){
        func(root->left,sum);
    }
    return root;
}

    TreeNode* bstToGst(TreeNode* root) { 
        int sum=0;
        TreeNode* ans=func(root,sum);
        return ans;   
    }
};