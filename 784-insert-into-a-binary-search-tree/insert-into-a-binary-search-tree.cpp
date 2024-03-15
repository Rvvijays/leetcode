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

    void print(TreeNode* root){
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            auto node = q.front();
            cout<<node->val<<" ";
            q.pop();

            if(node->left!=nullptr){
                q.push(node->left);
            }

            if(node->right!=nullptr){
                q.push(node->right);
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if (root==nullptr){
            return new TreeNode(val);
        }
        TreeNode* curr = root;

        while(true){
            // cout<<"node:"<<curr->val<<endl;
            if(curr->left == nullptr && curr->val > val){
                break;
            }

            if(curr->right == nullptr && curr->val < val){
                break;
            }

            if(curr->val < val){
                curr = curr->right;
            }else{
                curr = curr->left;
            }

            

            if(curr->left == nullptr && curr->right==nullptr){
                break;
            }

        }

        if(curr->val < val){
            curr->right = new TreeNode(val);
        }else{
            curr->left = new TreeNode(val);
        }

        // cout<<"breked at.."<<curr->val;

        return root;
    }
};