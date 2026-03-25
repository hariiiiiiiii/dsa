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
    vector<int> lowest;
    void dfs(TreeNode* root){
        if (!root) return;
        //vector<int> lowest;
        lowest.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        lowest.clear();
        dfs(root);
        sort(lowest.begin(),lowest.end());
        return lowest[k - 1];
    }
};