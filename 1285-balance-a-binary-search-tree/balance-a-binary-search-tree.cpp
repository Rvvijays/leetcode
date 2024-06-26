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

    void inorder(TreeNode* root, vector<int> &nums) {
        if(root==nullptr) {
            return;
        }

        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    TreeNode* build(int left, int right, vector<int> &nums) {
        // cout<<"left: "<<left<<" right: "<<right<<endl;

        if(left < 0 || right > nums.size() - 1 || left > right) {
            return nullptr;
        }

        if(left == right) {
            return new TreeNode(nums[left]);
        }

        int mid = (left + right) / 2;
        // cout<<"mid:::::"<<mid<<endl;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(left, mid-1, nums);
        root->right = build(mid+1, right, nums);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {

        vector<int> nums;
        inorder(root, nums);

        int n = nums.size();

        return build(0,n-1, nums);

        
    }
};