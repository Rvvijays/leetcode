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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> ans;

        if (root == nullptr) {
            return ans;
        }

        queue<pair<TreeNode*, int>> q;

        map<int,vector<pair<int,int>>> mp;

        q.push({root, 0});
        int level = 0;

        while (!q.empty()) {

            int size = q.size();

            for(int i=0; i<size; i++) {
                auto it = q.front();
                q.pop();
                TreeNode* node = it.first;
                int x = it.second;
                mp[x].push_back({level,node->val});

                if(node->left!=nullptr) {
                    q.push({node->left,x-1});
                }

                if(node->right!=nullptr) {
                    q.push({node->right,x+1});
                }
            }

            level++;

           
        }

        for(auto it : mp) {
            sort(it.second.begin(),it.second.end());
            vector<int> temp;
            for(auto [level,node] : it.second) {
                temp.push_back(node);
            }
                ans.push_back(temp);

        }

        return ans;
    }
};