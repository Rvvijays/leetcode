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

    void preorder(TreeNode* root,vector<int> &ans){
        if(root==nullptr){
            return;
        }

        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);

    }

    void brute(TreeNode* root){
        vector<int> ans;
        preorder(root,ans);

        TreeNode* curr = root;

        for(int i=1; i<ans.size(); i++){

            // if(curr!=nullptr){
                curr->left = nullptr;
                curr->right = new TreeNode(ans[i]);
                curr = curr->right;
            // }
            
        }

        // return root;
    }

    void optimal(TreeNode* root){

        TreeNode* curr = root;

        while(curr!=nullptr){
            if(curr->left!=nullptr){
                TreeNode* temp = curr->left;
                while(temp->right!=nullptr){
                    temp = temp->right;
                }

                temp->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }

            curr = curr->right;
        }


    }
    void flatten(TreeNode* root) {

        // brute(root);

        optimal(root);

        
        
    }
};