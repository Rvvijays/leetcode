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



    vector<vector<int>> verticalTraversal(TreeNode* root) {

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
};