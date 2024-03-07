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

    void mark(TreeNode* root,int level, int index, priority_queue<pair<int,pair<int,int>>> &pq){

        if(root==nullptr){
            return;
        }

        pq.push({index,{level,root->val}});

        mark(root->left,level+1,index-1,pq);
        mark(root->right,level+2,index+1,pq);

    }


    void print(priority_queue<pair<int,pair<int,int>>> &pq,stack<vector<int>> &ans){
        int index = pq.top().first;

        vector<int> temp;
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();

            if (index == node.first) {
                temp.push_back(node.second.second);

            } else {
               reverse(temp.begin(),temp.end());
               ans.push(temp);
               temp = vector<int>{};
               temp.push_back(node.second.second);
               index = node.first;
            }

            // cout<<"index: "<<node.first<<" val: "<<node.second.second<<endl;

            // cout<<node.first<<" ";
        }
        reverse(temp.begin(),temp.end());
        ans.push(temp);
    }


   vector<vector<int>> brute(TreeNode* root) {
       priority_queue<pair<int,pair<int,int>>> pq;
        mark(root,0,0,pq);
        stack<vector<int>> st;
        print(pq,st);
        vector<vector<int>> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;  
   }

    vector<vector<int>> traverse(TreeNode* root){
        queue<pair<TreeNode*,pair<int,int>>> q;

        map<int,map<int,multiset<int>>> nodes;

        // {index,{level,[node]}}

        q.push({root,{0,0}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int index = p.second.first;
            int level = p.second.second;
            nodes[index][level].insert(node->val);
            
            if(node->left!=nullptr){
                q.push({node->left,{index-1,level+1}});
            }
            if(node->right!=nullptr){
                q.push({node->right,{index+1,level+1}});
            }
        }

        vector<vector<int>> ans;

        for(auto p : nodes){
            vector<int> temp;

            for(auto q : p.second) {
            
               temp.insert(temp.end(),q.second.begin(), q.second.end());
                
            }

            ans.push_back(temp);
        }

        return ans;

    }


    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // return brute(root);

        return traverse(root);





           
    }
};