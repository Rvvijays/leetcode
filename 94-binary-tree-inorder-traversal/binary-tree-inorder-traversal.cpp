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

    vector<int> iterative(TreeNode* root){

        vector<int> ans;

        return ans;

    }

    void recursive(TreeNode* root, vector<int> &arr){

        if(root==nullptr){
            return;
        }

        recursive(root->left,arr);
        arr.push_back(root->val);
        recursive(root->right,arr);

    }
    vector<int> inorderTraversal(TreeNode* root) {

        // return iterative(root);
        vector<int> ans;
        recursive(root,ans);
        return ans;
        
    }
};