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

    int widthOfBinaryTree(TreeNode* root) {

        queue<pair<TreeNode*,int>> q;

        q.push({root,0});

        int width = 0;

        while(!q.empty()) {

            int size = q.size();

            int first,last;

            int minid = q.front().second;

            for(int i=0; i<size; i++) {

                auto it = q.front();
                q.pop();

                TreeNode* node = it.first;
                long id = it.second - minid;

                if(i==0){
                    first = id;
                }

                if(i == size - 1){
                    last = id;
                }

                if(node->left!=nullptr) {
                    q.push({node->left,2*id});
                }

                if(node->right!=nullptr) {
                    q.push({node->right,2*id+1});
                }
            }

            width = max(width, last-first+1);
        }

        return width;
        
        
    }
};