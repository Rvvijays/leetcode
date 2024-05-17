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

    bool isLeaf(TreeNode* root) {

        if(root->left == nullptr && root->right==nullptr) {
            return true;
        }

        return false;
    }

    void addLeaves(TreeNode* root, vector<int>& ans) {

        if(root==nullptr){
            return;
        }

        if(isLeaf(root)){
            ans.push_back(root->val);
        }

        addLeaves(root->left,ans);
        addLeaves(root->right,ans);
    }



    vector<int> boundaryOfBinaryTree(TreeNode* root) {

        vector<int> ans;

        if(!isLeaf(root)) {
            ans.push_back(root->val);

        }

        TreeNode* temp = root->left;
        while(temp!=nullptr) {
            if(!isLeaf(temp)){
                ans.push_back(temp->val);
            }

            if(temp->left!=nullptr) {
                temp = temp->left;
            }else{
                temp = temp->right;
            }
        }

        addLeaves(root,ans);

        stack<int> st;

        temp = root->right;
        while(temp!=nullptr) {
            if(!isLeaf(temp)){
                st.push(temp->val);
            }
            if(temp->right!= nullptr){
                temp = temp->right;
            }else{
                temp = temp->left;
            }
        }

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;





       
    }
};