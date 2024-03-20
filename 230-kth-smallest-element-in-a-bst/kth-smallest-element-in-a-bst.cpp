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

    void traverse(TreeNode* root, int k, vector<int> &ans){


        if(root==nullptr){
            return;
        }

       


        traverse(root->left,k,ans);
        if(ans.size() == k){
            return;
        }
        // cout<<"arr sie"<<ans.size()<<" adding:"<<root->val<<endl;

        ans.push_back(root->val);
       
        traverse(root->right,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {

        vector<int> ans;
        traverse(root,k,ans);

        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }

        return ans[k-1];


        
    }
};