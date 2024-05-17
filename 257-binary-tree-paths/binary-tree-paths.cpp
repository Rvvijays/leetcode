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

    void dfs(TreeNode* root, string curr, vector<string> &ans) {
        if(root==nullptr) {
            // ans.push_back(curr);
            return;
        }

        if(root->left == nullptr && root->right == nullptr) {
            curr += to_string(root->val);
            ans.push_back(curr);
            return;
        }


        

        dfs(root->left,curr + to_string(root->val) +"->",ans);
        dfs(root->right,curr + to_string(root->val) +"->",ans);

        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;


        string curr = "";
        dfs(root,curr,ans);

        return ans;

        
    }
};