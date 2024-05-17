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
    
    int findHeight(TreeNode* root, int &maxi){
        if(root==nullptr){
            return 0;
        }
        
        int leftHeight = findHeight(root->left,maxi);
        int rightHeight = findHeight(root->right,maxi);
        
        maxi = max(maxi, leftHeight+ rightHeight);
        
        return 1 + max(leftHeight,rightHeight);
    }
    
//     int recursion(TreeNode* root, int &maxi){
        
//         if(root==nullptr){
//             return 0;
//         }
        
//         int leftHeight = findHeight(root->left);
//         int rightHeight = findHeight(root->right);
        
//         // cout<<"root:"<<root->val<<endl;
//         // cout<<"left: "<<leftHeight<<" right:"<<rightHeight<<endl;
        
//         maxi = max(maxi,leftHeight + rightHeight);
        
//         return recursion(root->left,maxi) + recursion(root->right,maxi);
//     }
  
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        
        // recursion(root,maxi);
        findHeight(root,maxi);
        
        return maxi;
        
        
    }
};