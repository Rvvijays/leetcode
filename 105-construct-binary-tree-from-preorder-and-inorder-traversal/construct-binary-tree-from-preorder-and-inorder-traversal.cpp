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
    TreeNode* build(int preStart, int preEnd, int inStart, int inEnd, vector<int>& preorder, vector<int>&inorder) {
        if(preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);

        int rootIn = 0;

        for(int i=0; i<=inorder.size(); i++) {
            if(preorder[preStart] == inorder[i]){
                rootIn = i;
                break;
            }
        }

        int len = rootIn - inStart;

        
        root->left = build(preStart+1,preStart+len,inStart, rootIn-1, preorder,inorder);
        root->right = build(preStart+len+1,preEnd,rootIn+1,inEnd,preorder,inorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        if(n==0){
            return nullptr;
        }

        return build(0,n-1,0,n-1,preorder,inorder);
           
    }
};