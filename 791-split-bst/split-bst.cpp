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

    TreeNode* find(TreeNode* &root, int target) {
        if(root==nullptr || root->val == target) {
            return root;
        }

        if(root->val > target) {
            return find(root->left,target);
        }

        return find(root->right,target);

        
    }


    // TreeNode* traverse(TreeNode* root, int target,vector<TreeNode*> &ans) {
    //     if(root==nullptr) {
    //         return root;
    //     }

    //     TreeNode* left = traverse(root->left,target,ans);
    //     TreeNode* right = traverse(root->right,target,ans);

    //     if(left!=nullptr && left->val == target) {
    //         root->left = nullptr;

    //         ans.push_back(left);
    //     }

    //     if(right!=nullptr && right->val == target) {
    //         root->right = nullptr;
    //         ans.push_back(right);
    //     }
    //     // cout<<"traversed:"<<root->val<<endl;

    //     return root;
    // }

    void traverse(TreeNode* root, int target, vector<TreeNode*> &ans) {
        if(root==nullptr) {
            return;
        }

        if(root->val > target) {
            traverse(root->left,target,ans);
            root->left = ans[1];

            ans[1] = root;

           
        }else{

            traverse(root->right,target,ans);
            root->right = ans[0];

            ans[0] = root;
            
        }
    }

    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        

        vector<TreeNode*> ans(2,nullptr);

        traverse(root,target,ans);

        return ans;
        
    }
};