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

    TreeNode* build(int low, int high, vector<int>& nums) {

        cout<<"low: "<<low<<" high: "<<high<<endl;
       if(low>high) {
        return nullptr;
       }


       int mid = (low + high)/2;

       TreeNode* root = new TreeNode(nums[mid]);

       root->left = build(low,mid-1,nums);
       root->right = build(mid+1,high,nums);

       return root;

        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {

            return build(0,nums.size()-1,nums);
        
    }
};