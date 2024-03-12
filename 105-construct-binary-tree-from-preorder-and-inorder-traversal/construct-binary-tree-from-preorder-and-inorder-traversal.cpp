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
    TreeNode* generate(int preStart, int preEnd, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder, map<int,int> &mp){
        if(preStart>preEnd || inStart>inEnd){
            return nullptr;
        }


        TreeNode* root = new TreeNode(preorder[preStart]);

        int elem = mp[preorder[preStart]];

        int nElem = elem - inStart;

        root->left = generate(preStart+1,preStart+nElem,inStart,elem-1,preorder,inorder,mp);
        root->right = generate(preStart+nElem+1,preEnd,elem+1,inEnd,preorder,inorder,mp);

        return root;


        


    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        map<int,int> mp;

        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        return generate(0,preorder.size()-1,0,inorder.size()-1,preorder,inorder,mp);
        
    }
};