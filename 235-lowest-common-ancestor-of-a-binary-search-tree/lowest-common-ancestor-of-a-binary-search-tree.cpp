/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    TreeNode* traverse(TreeNode* root,  TreeNode* p, TreeNode* q){
        if(root == nullptr || root == p || root == q){
            return root;
        }

      
        TreeNode* left = traverse(root->left,p,q);
        TreeNode* right = traverse(root->right,p,q);
       


        if(left == p && right == q || left == q && right == p){
            return root;
        }

        if(left!=nullptr){
            return left;
        }

        return right;
    }

    TreeNode* optimal(TreeNode* root, TreeNode* p, TreeNode* q){

        if(root == nullptr){
            return nullptr;
        }

        if(p->val < root->val && q->val < root->val){
            return optimal(root->left,p,q);
        }else if(p->val > root->val && q->val > root->val){
            return optimal(root->right,p,q);
        }else{
            return root;
        }
        return nullptr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return optimal(root,p,q);
        
    }
};