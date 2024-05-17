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


    int postorder(TreeNode* root, vector<vector<int>> &ans) {
        if(root == nullptr) {
            return -1;
        }

        int left = postorder(root->left,ans);
        int right = postorder(root->right,ans);

        int curr = max(left , right) + 1;

        if(ans.size() == curr) {
            ans.push_back({});
        }

        ans[curr].push_back(root->val);

        // cout<<"key: "<<(left+right+1)<<endl;

        // mp[curr].push_back(root->val);


        return curr;

    }

    vector<vector<int>> findLeaves(TreeNode* root) {

        // unordered_map<int,vector<int>> mp;
        vector<vector<int>> ans;

        postorder(root,ans);


        // int size = mp.size();
        
        return ans;


    }
};