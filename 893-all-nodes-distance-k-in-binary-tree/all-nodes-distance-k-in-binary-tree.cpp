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

    void createMap(TreeNode* root, map<TreeNode*,TreeNode*> &mp){
        if(root == nullptr){
            return;
        }

        if(root->left!=nullptr){
            mp[root->left] = root;
        }

        if(root->right!=nullptr){
            mp[root->right] = root;

        }

        createMap(root->left,mp);
        createMap(root->right,mp);

    }


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        map<TreeNode*,TreeNode*> mp;
        createMap(root,mp);

        // for(auto k : mp) {
        //     cout<<"child:"<<k.first->val<<" root:"<<k.second->val<<endl;
        // }

        queue<TreeNode*> q;
        q.push(target);

        int level = 0;
        vector<int> ans;

        map<TreeNode*, bool> visited;
        visited[target] = true;
        while(!q.empty()){

            int size = q.size();
            

            for(int i=0; i<size; i++){
                auto node = q.front();
                q.pop();

               


                // cout<<"level: "<<level<<" node:"<<node->val<<endl;
                if(level==k){
                    ans.push_back(node->val);
                }
                // if(visited[node]==true){
                //     continue;
                // }



                if(node->left!=nullptr && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;

                }

                if(node->right!=nullptr && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;

                   
                }
                if(mp[node]!=nullptr && !visited[mp[node]]){
                    q.push(mp[node]);
                    visited[mp[node]] = true;

                    
                }
            }


            level++;


            if(level > k){
                return ans;
            }

            // level++;

        }


        return ans;
        
        
    }
};