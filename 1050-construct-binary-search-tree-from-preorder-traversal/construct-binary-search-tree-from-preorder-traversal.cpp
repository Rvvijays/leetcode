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

    TreeNode* generate(int preStart, int preEnd, int inStart, int inEnd, vector<int> &preorder, vector<int> &inorder){
        if(preStart > preEnd || inStart > inEnd){
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);

        int index = inStart;
        while(inorder[index]!=preorder[preStart]){
            index++;
        }

        int nElem = index - inStart;

        root->left = generate(preStart+1,preStart+nElem,inStart,index-1,preorder,inorder);
        root->right = generate(preStart+nElem+1,preEnd,index+1,inEnd,preorder,inorder);

        return root;


        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        vector<int> inorder = preorder;

        sort(inorder.begin(),inorder.end());

        return generate(0,preorder.size()-1,0, preorder.size()-1,preorder,inorder);


        
    }
};