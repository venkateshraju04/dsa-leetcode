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
    TreeNode* constructBST(TreeNode* root, int data){
        if(!root)return new TreeNode(data);
        if(root->val<data){
            root->right=constructBST(root->right,data);
        }else{
            root->left=constructBST(root->left,data);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root =NULL;
        for(int i=0;i<preorder.size();i++){
            root=constructBST(root, preorder[i]);
        }
        return root;
    }
};