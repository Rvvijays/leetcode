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

        } else {
            nums.push_back(root->val);
        }
        inorder(root->right, nums,fill);
    }

    int num = 0;

    void postOrder(TreeNode* root) {
        if(root==nullptr) {
            return;
        }

        postOrder(root->right);
        num += root->val;
        root->val = num;
        // num += 
        // cout<<"num: "<<root->val<<" ";
        
        postOrder(root->left);
    }

    int index =0;

    TreeNode* brute(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums, false);



        int n = nums.size();
        int nu = nums[n-1];
        for (int i = n - 2; i >= 0; i--) {
            nums[i] += nu;
            nu = nums[i];
            
        }

        inorder(root, nums, true);
        return root;
    }

    TreeNode* bstToGst(TreeNode* root) {

       postOrder(root);

       return root;
    }
};