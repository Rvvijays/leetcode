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
        stack<TreeNode*> st;
        vector<int> ans;
         if(root==nullptr){
            return ans;
        }

        TreeNode* curr = root;       

        while(true){
           
           if(curr!=nullptr){
                st.push(curr);
                curr = curr->left;
           }else{
                if(st.empty()){
                    break;
                }
                curr = st.top();
                st.pop();

                ans.push_back(curr->val);
                curr = curr->right;
                
           }

        }
        return ans;

    }

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

        // vector<int> ans;
        // recursive(root,ans);
        // return ans;

        return iterative(root);
        
    }
};