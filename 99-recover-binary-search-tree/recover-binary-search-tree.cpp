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

    void inorder(TreeNode* root, vector<int> &ans){
        if(root==nullptr){
            return;
        }

        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }

    void generate(TreeNode* root,vector<int> &index, vector<int> &ans){
        if(root==nullptr || index[0] == ans.size()){
            return;
        }

        generate(root->left,index,ans);
        root->val = ans[index[0]++];
        generate(root->right,index,ans);

    }

    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;

    void inorder2(TreeNode* root){
        if(root==nullptr){
            return;
        }


        inorder2(root->left);
        if(prev->val > root->val) {

            if(first == nullptr){
                first = prev;
                middle = root;
            }else{
                last = root;
            }


        }

        prev = root;
        inorder2(root->right);
    }

    void recoverTree(TreeNode* root) {

        prev = new TreeNode(INT_MIN);
        first = middle=last = nullptr;

        inorder2(root);

        if(first!=nullptr && last!=nullptr){
            int temp = first->val;
            first->val = last->val;
            last->val = temp;
        }else{
            int temp = first->val;
            first->val = middle->val;
            middle->val = temp;
        }

        // vector<int> prev;
        // inorder(root,prev);

        // sort(prev.begin(), prev.end());

        // vector<int> index(1,0);

        // generate(root,index,prev);
        
    }
};