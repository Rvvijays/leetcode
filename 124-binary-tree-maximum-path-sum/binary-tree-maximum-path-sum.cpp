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

    int path(TreeNode* root, int& ans){

        if(root==nullptr){
            return 0;
        }

        int left = path(root->left,ans);
        int right = path(root->right,ans);


        left = max(left,0);

        right = max(right,0);


        ans = max(ans,root->val+left+right);


        return root->val + max(left,right);

    }
    int maxPathSum(TreeNode* root) {

        int ans = INT_MIN;
       
        
        path(root,ans);
        return ans;
        
    }
};