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
    bool traverse(TreeNode* root,vector<int> &ans){
        if(root == nullptr){
            return true;
        }

       

        bool left = traverse(root->left,ans);
         if(ans.size()>0 && ans[ans.size()-1] >= root->val){
            // cout<<"false return "<<ans[ans.size()-1]<<":"<<root->val;
            return false;
        }
        ans.push_back(root->val);
        if(left==false){
            return false;
        }
        bool right = traverse(root->right,ans);

        return right;


    }

    bool optimal(TreeNode* root, long long low, long long high){
        if(root == nullptr){
            return true;
        }

        if(root->val <= low || root->val >= high){
            return false;
        }

        return optimal(root->left, low, root->val) && optimal(root->right, root->val,high);
    }
    bool isValidBST(TreeNode* root) {

        // vector<int> ans;
        // return traverse(root,ans);
        return optimal(root, LONG_MIN, LONG_MAX);
        
    }
};