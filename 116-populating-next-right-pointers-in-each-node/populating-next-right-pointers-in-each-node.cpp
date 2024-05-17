/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {

        if(root== NULL) {
            return NULL;
        }

        queue<Node*> q;



        q.push(root);

        while(!q.empty()) {
            int size = q.size();

            Node* prev = NULL;

            for(int i=0; i<size; i++) {
                Node* it = q.front();
                q.pop();
                if(prev == nullptr){
                    prev = it;
                }else{
                    prev->next = it;
                    prev = it;
                }


                if(it->left!=NULL){
                    q.push(it->left);
                }

                if(it->right!=NULL) {
                    q.push(it->right);
                }



            }
        }

        return root;
        
    }
};