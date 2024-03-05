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

    int height(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);

        return 1 + max(left,right);
    }

    bool check(TreeNode* root){
        if(root==nullptr){
            return true;
        }

        int left = height(root->left);
        int right = height(root->right);

        // cout<<"root:"<<root->val<<" left:"<<left<<" right:"<<right<<endl;



        if(abs(left - right) <= 1){
           bool leftCehck =  check(root->left);
           bool rightCeck = check(root->right);

           return leftCehck && rightCeck;
        }

        return false;



    }

    int postOrder(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        int left = postOrder(root->left);
        int right = postOrder(root->right);

        if(left == -1 || right == -1){
            return -1;
        }

        if(abs(left-right)<=1){
            return 1 + max(left,right);
        }

        return -1;

    }
    bool isBalanced(TreeNode* root) {

        // return check(root);

        int tt = postOrder(root);
        if(tt == -1){
            return false;
        }

        return true;
        
    }
};