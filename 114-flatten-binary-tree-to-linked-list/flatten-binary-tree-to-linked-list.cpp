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
    void flatten(TreeNode* root) {

        TreeNode* curr = root;
        while(curr!=nullptr) {
            if(curr->left!=nullptr) {

                TreeNode* right = curr->right;

                TreeNode* left = curr->left;

                curr->right = left;
                TreeNode* left1 = left;
                while(left->right!=nullptr) {
                    left = left->right;
                }

                left->right = right;
                curr->left = nullptr;

                curr = left1;

                
            }else{
                curr = curr->right;
            }
        }
        
    }
};