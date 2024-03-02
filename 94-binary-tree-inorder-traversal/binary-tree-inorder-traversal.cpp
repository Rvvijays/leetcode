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

        if(root== nullptr){
            return ans;
        }

        stack<TreeNode*> st;

        TreeNode* curr = root;
        while(true){
            if (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            } else {
                if(st.empty()){
                    break;
                }

                curr = st.top();
                ans.push_back(curr->val);
                st.pop();
                curr = curr->right;

            }
        }

        return ans;

    }

    void recursive(TreeNode* root, vector<int> &arr){

        if(root==nullptr){
            return;
        }

        recursive(root->left,arr);
        arr.push_back(root->val);
        recursive(root->right,arr);

    }
    vector<int> inorderTraversal(TreeNode* root) {

        return iterative(root);
        // vector<int> ans;
        // recursive(root,ans);
        // return ans;
        
    }
};