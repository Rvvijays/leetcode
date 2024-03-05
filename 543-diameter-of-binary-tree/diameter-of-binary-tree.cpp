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

    int check(TreeNode* root,vector<int>& ans){

        if(root==nullptr){
            return 0;
        }

        int left = check(root->left,ans);
        int right = check(root->right,ans);

        ans[0] = max(ans[0],left+right);

        return 1 + max(left,right);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        vector<int> ans(1,0);

        check(root,ans);

        return ans[0];
        
    }
};