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
    vector<vector<int>> levelOrder(TreeNode* root) {

      
        vector<vector<int>> ans;
          if(root==nullptr){
            return ans;
        }
        queue<TreeNode*> q;

        q.push(root);


        while(!q.empty()){

            vector<int> arr;
            // cout<<"q:size:"<<q.size();
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                arr.push_back(node->val);

                if(node->left!=nullptr){
                    q.push(node->left);
                }

                if(node->right!=nullptr){
                    q.push(node->right);
                }

            }

            ans.push_back(arr);
           



        }

        return ans;
        
    }
};