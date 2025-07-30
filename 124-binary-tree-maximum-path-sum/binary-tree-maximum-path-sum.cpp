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
    int findMax(TreeNode* node, int& res) {
        if (!node) {
            return 0;
        }

        int leftSum = max(0, findMax(node->left, res));
        int rightSum = max(0, findMax(node->right, res));

        res = max(res, leftSum + rightSum + node->val);
        return node->val + max(leftSum, rightSum) ;
    }

    int maxPathSum(TreeNode* root) {
        int res = root->val;
        findMax(root, res);
        return res;
    }
};