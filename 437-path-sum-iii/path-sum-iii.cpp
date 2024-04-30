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
    int ans;
    void dfs(TreeNode* root, long long target) {

        if(root==nullptr){
            return;
        }

        if(root->val == target){
            ans++;
        }

        // if(target >= root->val){
        dfs(root->left, target - root->val);
        dfs(root->right, target - root->val);
        // }

        







    }
    int pathSum(TreeNode* root, int targetSum) { 
        if(root!=nullptr){

            dfs(root, targetSum);
            pathSum(root->left,targetSum);
            pathSum(root->right,targetSum);

        }

        return ans;
    }
};