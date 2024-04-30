/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int ans = INT_MIN;
void dfs(TreeNode* root, int dir, int len){
	if(root==nullptr){
		ans = max(ans,len);
		return;
	}
	
	if(dir == 0){
		dfs(root->left, -1,len+1);
		dfs(root->right, 1, len+1);
		
	}else{
		if(dir == -1){
			dfs(root->left,-1,1);
			dfs(root->right,1,len+1);
		}else{
			dfs(root->right,1,1);
			dfs(root->left,-1,len+1);
		
		}
	}
}

    int longestZigZag(TreeNode* root) {

        dfs(root,0,0);

        return ans-1;
      



    }
};