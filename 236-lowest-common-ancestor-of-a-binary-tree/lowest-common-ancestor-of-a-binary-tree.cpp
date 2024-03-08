/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    
  
    bool generate(TreeNode* root,TreeNode* target,vector<TreeNode*> &ans){
        if(root == nullptr){
            return false;
        }

        if(root == target){
           
            return true;
        }

        if(root->left!=nullptr){
            ans.push_back(root->left);
            if(generate(root->left,target,ans)){
                return true;
            }
            ans.pop_back();
        }

        if(root->right!=nullptr){
            ans.push_back(root->right);
            if(generate(root->right,target,ans)){
                return true;
            }
            ans.pop_back();
        }

        return false;
    }

    TreeNode* brute(TreeNode* root, TreeNode* p, TreeNode* q){
        vector<TreeNode*> pathp;
        vector<TreeNode*> pathq;
        pathp.push_back(root);
        pathq.push_back(root);
        generate(root,p,pathp);
        generate(root,q,pathq);

        int i=0;
        int j=0;

        TreeNode* lca = nullptr;

        while(i<pathp.size() && j<pathq.size()){

            if(pathp[i] == pathq[j]){
                lca = pathp[i];
            }else{
                break;
            }

            i++;
            j++;

        }

       return lca;
    }

    TreeNode* traverse(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr){
            return root;
        }

        if(root == p){
            return p;
        }

        if(root == q){
            return q;
        }

        cout<<"root:"<<root->val<<endl;

        if(root->left!=nullptr){
            cout<<"left:"<<root->left->val<<endl;
        }

         if(root->right!=nullptr){
            cout<<"right:"<<root->right->val<<endl;
        }

        TreeNode* left = traverse(root->left,p,q);

        TreeNode* right = traverse(root->right,p,q);

        // if(left!=nullptr && right!=nullptr && left == p && right == q){
        //     cout<<"left:"<<left->val<<" right:"<<right->val<<endl;
        //     return root;
        // }

        if((left == p && right == q) || (left == q && right == p)){
            return root;
        }



    

        if(left != nullptr){
            return left;
        }

        return right;

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    // return brute(root,p,q);

    return traverse(root,p,q);


    
    }
};