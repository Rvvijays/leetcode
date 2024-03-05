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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        queue<TreeNode*> q;

        vector<vector<int>> ans;

        if(root==nullptr){
            return ans;
        }

        q.push(root);

        bool flag = false;

        while(!q.empty()){

            int size = q.size();
            vector<int> temp;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                // if(flag){
                //     temp.push_front(node->val);
                // }else{
                    temp.push_back(node->val);
                // }

                if(node->left!=nullptr){
                    q.push(node->left);
                }

                if(node->right!=nullptr){
                    q.push(node->right);
                }
                
            }

            if(flag){
                reverse(temp.begin(),temp.end());
            }

                flag = !flag;


            ans.push_back(temp);



        }

        return ans;
        
    }
};