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

    TreeNode* generate(int inStart, int inEnd, int postStart, int postEnd, vector<int>& inorder, vector<int>& postorder, map<int,int> &mp){
        if(inStart>inEnd || postStart> postEnd){
            return nullptr;
        }

        TreeNode* node = new TreeNode(postorder[postEnd]);

        int elem = mp[postorder[postEnd]];
        int nElem = elem - inStart;

        // cout<<"inStart:"<<inStart<<" inEnd:"<<inEnd<<" postStart:"<<postStart<<" postEnd:"<<postEnd<<endl;

        node->left = generate(inStart,elem-1, postStart,postStart+nElem-1,inorder,postorder,mp);
        node->right = generate(elem+1,inEnd, postStart+nElem,postEnd-1,inorder,postorder,mp);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        map<int,int> mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        return generate(0,inorder.size()-1,0,postorder.size()-1,inorder,postorder,mp);
        
    }
};