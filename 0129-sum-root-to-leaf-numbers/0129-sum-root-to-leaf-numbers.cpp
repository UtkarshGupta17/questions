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
int func(TreeNode* root,int &val,int current){
    if(!root){
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr){
        val += (current * 10 + root->val);
    }
    current = current * 10 + root->val; 
    func(root->left,val,current);
    func(root->right,val,current);
    

    return val;
}
    int sumNumbers(TreeNode* root) {

        int val=0;
        func(root,val,0);
        return val;

        
    }
};