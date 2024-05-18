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
    TreeNode* ans;
    void inorder(TreeNode* root) {
        if(root==nullptr){
            return;
        }

        inorder(root->left);

        root->left = nullptr;
        ans->right = root;
        ans = ans->right;

        inorder(root->right);

    }
    TreeNode* increasingBST(TreeNode* root) {

        if(root==nullptr) {
            return nullptr;
        }
        ans = new TreeNode(0);
        TreeNode* curr = ans;
        inorder(root);

        return curr->right;
        
    }
};