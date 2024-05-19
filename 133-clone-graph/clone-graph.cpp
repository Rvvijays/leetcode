/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* build(Node* node,unordered_map<Node*,Node*> &mp) {
        if(node == nullptr) {
            return nullptr;
        }

        Node* root = new Node(node->val);
        mp[node] = root;

        vector<Node*> children;
        for (auto child: node->neighbors) {
            if(mp.find(child) == mp.end()) {
                // mp[child] = true;
                Node* temp = build(child,mp);
                children.push_back(temp);

            }else{
                // Node* temp = new Node(child->val);
                children.push_back(mp[child]);
            }
        }

        root->neighbors = children;

        return root;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        return build(node,mp);
      
    }
};