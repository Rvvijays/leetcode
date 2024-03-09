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

        if(root== nullptr){
            return 0;
        }

        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});

        int width = 0;

        while(!q.empty()){
            
            int size = q.size();

            int startIndex = 0;
            int lastIndex = 0;
            int currMin = q.front().second;


            for(int i=0; i<size; i++){
                auto p = q.front();
                q.pop();

                TreeNode* node = p.first;
                long long index = p.second - currMin;
                if(i==0){
                    startIndex = index;
                }
                lastIndex = index;
                

                if(node->left!=nullptr){
                    q.push({node->left,2*index});
                }

                if(node->right!=nullptr){
                    q.push({node->right,2*index+1});
                }
            }

            
            width = max(width,lastIndex-startIndex +1);
       

        }

        return width;

    }
};