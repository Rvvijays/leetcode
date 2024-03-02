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
    void recursive(TreeNode* root,vector<int> &arr){
        if(root==nullptr){
            return;
        }

        recursive(root->left,arr);
        recursive(root->right,arr);
        arr.push_back(root->val);
    }

    vector<int> iterative(TreeNode* root){
        vector<int> ans;

        if(root==nullptr){
            return ans;
        }

        stack<TreeNode*> st1;
        stack<TreeNode*> st2;

        st1.push(root);

        while(!st1.empty()){
            TreeNode* node = st1.top();
            st1.pop();
            st2.push(node);
           
            if(node->left!=nullptr){
                st1.push(node->left);
            }

             if(node->right!=nullptr){
                st1.push(node->right);
            }
           
            
        }

        while(!st2.empty()){
            TreeNode* node = st2.top();
            ans.push_back(node->val);
            st2.pop();
        }

        return ans;

    }
    vector<int> postorderTraversal(TreeNode* root) {

        // vector<int> ans;

        // recursive(root,ans);

        // return ans;

        return iterative(root);
        
    }
};