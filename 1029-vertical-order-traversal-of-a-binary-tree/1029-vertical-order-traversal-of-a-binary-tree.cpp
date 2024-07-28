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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        
        // map: column -> list of pairs (row, value)
        map<int, vector<pair<int, int>>> nodes_map;
        queue<pair<TreeNode*, pair<int, int>>> q; // node, (column, row)
        
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            
            TreeNode* node = p.first;
            int col = p.second.first;
            int row = p.second.second;
            
            nodes_map[col].emplace_back(row, node->val);
            
            if (node->left) {
                q.push({node->left, {col - 1, row + 1}});
            }
            if (node->right) {
                q.push({node->right, {col + 1, row + 1}});
            }
        }
        
        vector<vector<int>> result;
        
        for (auto& col_nodes : nodes_map) {
            auto& nodes = col_nodes.second;
            sort(nodes.begin(), nodes.end());
            vector<int> col_values;
            for (auto& node : nodes) {
                col_values.push_back(node.second);
            }
            result.push_back(col_values);
        }
        
        return result;
    }
};