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

    void  traverse(TreeNode* root, int low, int high,int &sum) {
        if(root == nullptr) {
            return;
        }

        traverse(root->left,low,high, sum);
        traverse(root->right,low,high, sum);

        cout<<"val:"<<root->val<<endl;

        if(root!=nullptr && root->val >= low && root->val <= high) {
            sum += root->val;
        }

        // if(root!=nullptr && root->val >= low && root->val <= high) {
        //     sum += root->val;
        // }
        // return root;

    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;

        traverse(root,low,high,sum);

        return sum;
    }
};