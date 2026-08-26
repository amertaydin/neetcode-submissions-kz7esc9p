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
    bool flag = true;
public:
    bool isBalanced(TreeNode* root) {
        int res = findHeight(root);
        return flag;
    }

    int findHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int l = findHeight(root->left);
        int r = findHeight(root->right);

        if (abs(r - l) > 1) flag = false;

        return 1 + max(r, l);
    }
};
