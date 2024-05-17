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
    bool checkTree(TreeNode* root) {

        if(root==nullptr){
            return true;
        }

        if(root->left == nullptr && root->right == nullptr){
            return true;
        }


        cout<<"root: "<<root->val<<endl;

        int left = root->left!=nullptr ? root->left->val:0;
        int right = root->right!=nullptr ? root->right->val:0;

        cout<<"left: "<<left<<endl;
        cout<<"right: "<<right<<endl;


        if(left + right != root->val){
            return false;
        }

        return checkTree(root->left) && checkTree(root->right);


        
    }
};