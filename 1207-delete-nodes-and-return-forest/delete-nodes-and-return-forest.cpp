/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = countNodes(root->left);
        int right = countNodes(root->right);

        return left + right + 1;
    }

    void dfs(TreeNode* &root, vector<int> & to_delete,vector<TreeNode*> &ans) {

        if (root == nullptr) {
            return;
        }

        
        dfs(root->left, to_delete,ans);
        dfs(root->right, to_delete,ans);

        if(find(to_delete.begin(),to_delete.end(),root->val)!=to_delete.end()) {
            if(root->left!=nullptr) {
                ans.push_back(root->left);
            }

            if(root->right!=nullptr) {
                ans.push_back(root->right);
            }

            root = nullptr;
            delete root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {

        vector<TreeNode*> ans;

        if(root==nullptr){
            return ans;
        }

        dfs(root,to_delete,ans);

        if(root){
            ans.push_back(root);
        }

        return ans;
        
        
    }
};