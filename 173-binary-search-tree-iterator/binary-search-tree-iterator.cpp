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
class BSTIterator {
public:
    queue<int> ans;

    void inorder(TreeNode* root, queue<int> &ans){
        if(root==nullptr){
            return;
        }

        inorder(root->left,ans);
        ans.push(root->val);
        inorder(root->right,ans);
    }

    BSTIterator(TreeNode* root) {

        inorder(root,ans);
        
    }
    
    int next() {

        int n =  ans.front();
        ans.pop();


        return n;
        
    }
    
    bool hasNext() {

        return !ans.empty();
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */