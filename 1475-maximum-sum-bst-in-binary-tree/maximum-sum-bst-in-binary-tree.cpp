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

class NodeHelper{
    

    public:
    int min;
    int max;
    int sum;
    NodeHelper(int min, int max, int sum) {
        this->min = min;
        this->max = max;
        this->sum = sum;

    }
};
class Solution {
public:

    NodeHelper* traverse(TreeNode* root,int &maxi) {
      if(root == nullptr) {
        return new NodeHelper(INT_MAX,INT_MIN,0);
      }

      NodeHelper* left = traverse(root->left,maxi);
      NodeHelper* right = traverse(root->right,maxi);

      if(root->val > left->max && root->val < right->min) {
        // valid

        // cout<<"returned : "<<(left->sum + right->sum + root->val)<<endl;

        maxi = max(maxi,left->sum + right->sum + root->val);

        return new NodeHelper(min(left->min, root->val), max(right->max,root->val),left->sum + right->sum + root->val);
      }

      return new NodeHelper(INT_MIN,INT_MAX,max(left->sum,right->sum));

    }
    int maxSumBST(TreeNode* root) {

        int maxi = 0;
        traverse(root,maxi);

        return maxi;
        
    }
};