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
bool func(TreeNode* root,int value,string &path){
    if(!root){
        return false;
    }
    if(root->val==value){
        return true;
    }
    path.push_back('L');
    if(func(root->left,value,path)){
        return true;
    }
    path.pop_back();
    path.push_back('R');
    if(func(root->right,value,path)){
        return true;
    }
    path.pop_back();
    return false;
}
    string getDirections(TreeNode* root, int startValue, int destValue) {
       string start, end;
        func(root, startValue, start);
        func(root, destValue, end);
        int i = 0;
        while (i < start.size() && i < end.size() && start[i] == end[i]) {
            i++;
        }
        string result(start.size() - i, 'U');
        cout<<end.substr(i);
        result += end.substr(i);

        return result;     
    }
};