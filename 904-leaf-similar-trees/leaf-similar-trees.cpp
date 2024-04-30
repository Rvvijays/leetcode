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

   void dfs(TreeNode* root, vector<int> &ans){
    if(root==nullptr){
        return;
    }

    if(root->left==nullptr && root->right==nullptr){
        ans.push_back(root->val);
    }

    dfs(root->left,ans);
    dfs(root->right,ans);
   }
   
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }

        if (root1 == nullptr || root2 == nullptr) {
            return false;
        }

        vector<int> leafNodes1;
        vector<int> leafNodes2;

       dfs(root1,leafNodes1);
         dfs(root2,leafNodes2);

        
        

       

        return leafNodes1 == leafNodes2;
    }
};