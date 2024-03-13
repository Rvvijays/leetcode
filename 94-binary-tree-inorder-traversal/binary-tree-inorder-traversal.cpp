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

    vector<int> morris(TreeNode* root){
        TreeNode* curr = root;
        vector<int> ans;
        if(root == nullptr){
            return ans;
        }

        while(curr!=nullptr){
            if(curr->left==nullptr){
                ans.push_back(curr->val);
                curr = curr->right;
            }else{
                TreeNode* temp = curr->left;
                while(temp->right!=nullptr && temp->right!=curr){
                    temp = temp->right;
                }

                if(temp->right == nullptr){
                    temp->right = curr;
                    curr = curr->left;
                }else{
                    temp->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;



                }
            }
        }
        return ans;

    }
    vector<int> inorderTraversal(TreeNode* root) {

        // vector<int> ans;
        // recursive(root,ans);
        // return ans;

        // return iterative(root);

        return morris(root);

        
    }
};