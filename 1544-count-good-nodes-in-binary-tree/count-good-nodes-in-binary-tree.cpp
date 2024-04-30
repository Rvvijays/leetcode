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

    int dfs(TreeNode* root, int maxi){
	if(root==nullptr){
		return 0;
	}
	
	int count = 0;
	
	if(root->val >= maxi){
		count += 1;
	}
	
	int fromleft = dfs(root->left,max(root->val,maxi));
	int fromRight = dfs(root->right,max(maxi, root->val));
	
	return count + fromleft + fromRight;
}
    int goodNodes(TreeNode* root) {

        return dfs(root,root->val);
        
    }
};