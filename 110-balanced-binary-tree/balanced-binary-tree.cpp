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

    int height(TreeNode* root) {
        if(root==nullptr) {
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);

        if(left == -1 || right == -1){
            return -1;
        }

        if(abs(left-right) >1){
            return -1;
        }

        return max(left,right) + 1;
    }


    bool isBalanced(TreeNode* root) {

        if(root==nullptr) {
            return true;
        }

        // int left = height(root->left);
        // int right = height(root->right);

        // if(abs(left-right) > 1) {
        //     return false;
        // }

        // return isBalanced(root->left) && isBalanced(root->right);

        int h = height(root);

        return h == -1 ? false: true;
        
        
    }
};