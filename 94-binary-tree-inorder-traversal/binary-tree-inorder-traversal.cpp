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

    void recursive(TreeNode* root,vector<int> &ans) {
        if(root==nullptr){
            return;
        }

        recursive(root->left,ans);
        ans.push_back(root->val);
        recursive(root->right,ans);
    }

    void iterative(TreeNode* root, vector<int> &ans) {
        if(root== nullptr) {
            return;
        }

        stack<TreeNode*> st;
        TreeNode* curr = root;

        while(true) {
            if(curr != nullptr) {
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
    } 

    void morris(TreeNode* root, vector<int> &ans) {
        if(root==nullptr) {
            return;
        }

        TreeNode* curr = root;

        while(curr!=nullptr) {

            if(curr->left==nullptr) {
                ans.push_back(curr->val);
                curr = curr->right;

            }else{
                TreeNode* temp = curr->left;

                while(temp != nullptr && temp->right!=curr) {
                    temp = temp->right;
                }

                if(temp->right == nullptr) {
                    temp->right = curr;
                    curr = curr->left;

                }else{
                    temp->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;

                }
            }
        }
    }


    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        iterative(root,ans);
        

        return ans;
    }
};