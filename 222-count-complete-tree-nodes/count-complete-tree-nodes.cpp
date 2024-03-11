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
    void generate(TreeNode* root,vector<int> &num) {

        if(root==nullptr){
            return;
        }

        num[0]++;
        generate(root->left,num);
        generate(root->right,num);
    }
    int countNodes(TreeNode* root) {

        vector<int> num(1,0);
        generate(root,num);

        return num[0];

    
        
    }
};