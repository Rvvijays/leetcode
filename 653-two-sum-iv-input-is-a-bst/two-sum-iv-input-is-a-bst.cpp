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

class BSTIterator{
    public:

    stack<TreeNode*> st;
    bool reverse;

    BSTIterator(TreeNode* root,bool isReverse){
        reverse = isReverse;
        while(root!=nullptr){
            st.push(root);
            if(reverse){
                root = root->right;
            }else{
                root = root->left;
            }
        }
    }

    int next(){
        TreeNode* node = st.top();
        st.pop();

        if(reverse){
            if(node->left!=nullptr){
                TreeNode* left = node->left;
                while(left!=nullptr){
                    st.push(left);
                    left = left->right;
                }
            }
        }else{
            if(node->right!=nullptr){
                TreeNode* right = node->right;
                while(right!=nullptr){
                    st.push(right);
                    right = right->left;
                }
            }
        }
        return node->val;
    }

    bool hasNext(){
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {

        auto low = new BSTIterator(root,false);
        auto high = new BSTIterator(root,true);


        int l = low->next();
        int h = high->next();

        while(l!=h && low->hasNext() && high->hasNext()){

            int sum = l + h;

            // cout<<"low:"<<l<<" high:"<<h<<" ="<<sum<<endl;;


            if(sum == k){
                return true;
            }

            if(sum > k){
                h = high->next();
            }else{
                l = low->next();
            }
        }

        return false;
        
    }
};