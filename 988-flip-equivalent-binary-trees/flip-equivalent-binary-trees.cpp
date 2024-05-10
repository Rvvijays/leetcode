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
    void traversal(TreeNode* root, vector<int> &ans){
        if(root==nullptr){
            return;
        }
        ans.push_back(root->val);
        
        int left = root->left!=nullptr?root->left->val:-1;
        int right = root->right!=nullptr?root->right->val:-1;
        
        if(left < right){
            traversal(root->left,ans);
            traversal(root->right,ans); 
        }else{
            traversal(root->right,ans); 
            traversal(root->left,ans);
        
        }
        
        ans.push_back(-1);
        
    }
    
    bool recursion(TreeNode* root1, TreeNode* root2){
          if (root1 == root2) {
            return true;
        }

        if (root1 == nullptr || root2 == nullptr || root1->val != root2->val) {
            return false;
        }

 
        return flipEquiv(root1->left, root2->left) &&
               flipEquiv(root1->right, root2->right) ||
               flipEquiv(root1->left, root2->right) &&
               flipEquiv(root1->right, root2->left);
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
  if (root1 == root2) {
            return true;
        }

        if (root1 == nullptr || root2 == nullptr || root1->val != root2->val) {
            return false;
        }
        // return recursion(root1,root2);
        
        vector<int> list1;
        vector<int> list2;
        
        traversal(root1,list1);
        traversal(root2,list2);
        
        
        if(list1.size() != list2.size()){
            return false;
        }
        
        for(int i=0; i<list1.size(); i++){
            cout<<list1[i]<<" ";
        }
        
        cout<<endl;
        
        for(int i=0; i<list1.size(); i++){
            cout<<list2[i]<<" ";
        }
        
        for(int i=0; i<list1.size(); i++){
            if(list1[i] != list2[i]){
                return false;
            }
        }
        
        return true;
      
    }
};