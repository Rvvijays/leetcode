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

    void inorder(TreeNode* root, vector<int> &ans){
        if(root==nullptr){
            return;
        }

        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }

    void generate(TreeNode* root,vector<int> &index, vector<int> &ans){
        if(root==nullptr || index[0] == ans.size()){
            return;
        }

        generate(root->left,index,ans);
        root->val = ans[index[0]++];
        generate(root->right,index,ans);

    }

    void recoverTree(TreeNode* root) {

        vector<int> prev;
        inorder(root,prev);

        sort(prev.begin(), prev.end());

        vector<int> index(1,0);

        generate(root,index,prev);
        
    }
};