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
    TreeNode* findLastRightNode(TreeNode* root){
        if(root->right==NULL){
            return root;
        }
        return findLastRightNode(root->right);
    }
    TreeNode* connectNode(TreeNode* root){
        if(root->left==NULL){
            return root->right;
        }else if(root->right==NULL){
            return root->left;
        }
        TreeNode* rightNode=root->right;
        TreeNode* lastRightNode=findLastRightNode(root->left);
        lastRightNode->right=rightNode;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return NULL;
        if(root->val==key)return connectNode(root);
        TreeNode* temp=root;
        while(root){
            if(root->val>key){
                if(root->left!=NULL && root->left->val==key){
                    root->left=connectNode(root->left);
                    break;
                }else{
                    root=root->left;
                }
            }else{
                if(root->right!=NULL && root->right->val==key){
                    root->right=connectNode(root->right);
                    break;
                }else{
                    root=root->right;
                }
            }
        }
        return temp;
    }
};