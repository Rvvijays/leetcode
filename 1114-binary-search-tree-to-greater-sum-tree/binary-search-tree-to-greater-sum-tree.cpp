 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& nums, bool fill) {
        if (root == nullptr) {
            return;
        }

        inorder(root->left, nums,fill);
        if (fill) {

            root->val = nums[index++];
            // cout<<root->val<<" ";

        } else {
            // cout<<root->val<<" ";
            nums.push_back(root->val);
        }
        inorder(root->right, nums,fill);
    }

    int index =0;

    TreeNode* bstToGst(TreeNode* root) {

        vector<int> nums;
        // cout<<"inorder: ";
        inorder(root, nums, false);



        int n = nums.size();
        int nu = nums[n-1];
        for (int i = n - 2; i >= 0; i--) {
            // nu = nums[i]
            nums[i] += nu;
            nu = nums[i];
            
        }

        // cout<<"inorder oo: ";
        inorder(root, nums, true);
        return root;
    }
};