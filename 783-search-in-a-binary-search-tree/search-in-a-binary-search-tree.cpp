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
    TreeNode* search(TreeNode* root,int val){
        if(root==nullptr || root->val == val){
            return root;
        }

        if(root->val < val){
            return search(root->right,val);
        }

        return search(root->left,val);
    }

    TreeNode* iterative(TreeNode* root,int val){

        // if(root==nullptr){
        //     return root;
        // }
        while(root!=nullptr && root->val!=val){
            if(root->val < val){
                root = root->right;
            }else{
                root = root->left;
            }
        }

        return root;
    }
    TreeNode* searchBST(TreeNode* root, int val) {

        // return search(root,val);
        return iterative(root,val);
        
    }
};