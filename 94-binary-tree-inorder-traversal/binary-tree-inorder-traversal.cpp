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

    // vector<int> iterative(TreeNode* root){

    //     stack<TreeNode*> st;
    //     vector<int> ans;

    //     TreeNode* curr = root;
    //     st.push(curr);
    //     while(curr->left!=nullptr){
    //         st.push(curr);
    //         curr = curr->left;
    //     }


    //     while(!st.empty()){
    //         curr = st.top();
    //         st.pop();
            
            
    //         ans.push_back(curr->val);

    //         // if(curr->right!=nullptr){
    //         //     st.push(curr-)
    //         // }




    //     }

    // }

    void recursive(TreeNode* root,vector<int>& ans){
        if(root==nullptr){
            return;
        }

        recursive(root->left,ans);
        ans.push_back(root->val);
        recursive(root->right,ans);

    }

    // vector<int> morris(TereNode* root){

    // }
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;
        recursive(root,ans);
        return ans;
        
    }
};