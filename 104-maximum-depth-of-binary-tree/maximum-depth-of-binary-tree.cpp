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


    int iterative(TreeNode* root){
 if(root==nullptr){
            return 0;
        }
        queue<TreeNode*> q;
        int depth = 0;


        q.push(root);

        while(!q.empty()){
           
            int size = q.size();
            // cout<<"level: "<<depth<<": ";
            for(int i=0; i<size; i++){
                TreeNode* temp = q.front();
                // cout<<temp->val;
                q.pop();

                if(temp->left!=nullptr){
                    q.push(temp->left);
                }

                if(temp->right!=nullptr){
                    q.push(temp->right);
                }

            }

            depth++;

        }


        return depth;

    }

    int recursive(TreeNode* root){
        if(root==nullptr){
            return 0;
        }

        int left = recursive(root->left);
        int right = recursive(root->right);

        return 1 + max(left,right);
    }

    
    int maxDepth(TreeNode* root) {

        // return iterative(root);

        return recursive(root);

       
        
    }
};