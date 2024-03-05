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

    bool check(TreeNode* a, TreeNode* b){


        if(a == nullptr && b==nullptr){
            return true;
        }

        if(a==nullptr || b == nullptr){
            return false;
        }

        if(a->val!=b->val){
            return false;
        }

        bool aa = check(a->left,b->left);
        bool bb = check(a->right,b->right);

        return aa && bb;


    }

    void inorder(TreeNode* root,vector<int>& ans){
        if(root == nullptr){
            return;
        }

        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {

       return check(p,q);
        
    }
};