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
        if (findHeight(root) == -1) return false;
        return true;
    }

    int findHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int l = findHeight(root->left);
        if (l == -1) return -1;
        int r = findHeight(root->right);
        if (r == -1) return -1;

        if (abs(r - l) > 1) return -1;

        return 1 + max(r, l);
    }
};
