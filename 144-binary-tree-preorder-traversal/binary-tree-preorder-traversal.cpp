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

    void iterative(TreeNode* root, vector<int> &ans) {
        if(root==nullptr){
            return;
        }

        // TreeNode* curr = root;

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {

            TreeNode* node = st.top();
            st.pop();
            
            ans.push_back(node->val);

           


            if(node->right!=nullptr){
                st.push(node->right);
            }

             if(node->left!=nullptr) {
                st.push(node->left);
            }
        }
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        iterative(root,ans);

        return ans;
    }

    void recursive(TreeNode* root, vector<int> &ans) {
        if(root==nullptr){
            return;
        }

        ans.push_back(root->val);
        recursive(root->left,ans);
        recursive(root->right,ans);
    }
};