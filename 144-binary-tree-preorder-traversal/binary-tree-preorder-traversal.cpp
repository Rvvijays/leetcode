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

    vector<int> iterative(TreeNode* root){
        vector<int> ans;
        stack<TreeNode*> st;

        if(root==nullptr){
            return ans;
        }
        st.push(root);

        while(!st.empty()){
            TreeNode* el = st.top();
            st.pop();

            ans.push_back(el->val);
            if(el->right!=nullptr){
                st.push(el->right);
            }

            if(el->left!=nullptr){
                st.push(el->left);
            }
        }

        return ans;
    }
    vector<int> preorderTraversal(TreeNode* root) {

        return iterative(root);
        
    }
};