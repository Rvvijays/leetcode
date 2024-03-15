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
    vector<int> rightSideView(TreeNode* root) {

        if(root==nullptr){
            return vector<int>{};
        }

        queue<TreeNode*> q;

        vector<int> ans;
       

        q.push(root);

        while(!q.empty()){
            int size = q.size();
            
           TreeNode* node = nullptr;
            for(int i=0; i<size; i++){
               node = q.front();
                q.pop();

                if(node->left!=nullptr){
                    q.push(node->left);
                }

                if(node->right!=nullptr){
                    q.push(node->right);
                }
            }

            ans.push_back(node->val);

            
            
        }

        return ans;
        
    }
};