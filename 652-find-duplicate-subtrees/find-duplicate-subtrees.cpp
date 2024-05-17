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

    string traverse(TreeNode* root, unordered_map<string,int> &cnt, vector<TreeNode*> &roots) {
        if(root== nullptr) {
            return "";
        }

        string rep = "(" + traverse(root->left,cnt,roots) +")"+to_string(root->val)+"("+traverse(root->right,cnt,roots)+")";
        cnt[rep]++;

        if(cnt[rep]==2) {
            roots.push_back(root);
        }

        return rep;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

        unordered_map<string,int> cnt;
        vector<TreeNode*> ans;

        traverse(root,cnt,ans);

        return ans;
        
    }
};