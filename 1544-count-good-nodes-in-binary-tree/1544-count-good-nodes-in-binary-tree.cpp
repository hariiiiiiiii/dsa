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
    int dfs(TreeNode* root, int max_so_far){
        if (root == nullptr) return 0;

        int count = 0;
        if(root->val >= max_so_far){
            count = 1;
        }
        int current_max = max(max_so_far, root->val);

        count += dfs(root->left,current_max);
        count += dfs(root->right,current_max);
        return count;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
};