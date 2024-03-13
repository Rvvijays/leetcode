/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        string s = "";

        if(root== nullptr){
            return "#";
        }

        queue<pair<TreeNode*,string>> q;
        q.push({root,to_string(root->val)});
        while(!q.empty()){
            int size = q.size();

            for(int i=0; i<size; i++){
                auto p = q.front();
                q.pop();
                TreeNode* node = p.first;
                string str = p.second;
                s += str+",";
                

                // cout<<"queue.pop"<<str<<endl;

                if(node == nullptr){
                    continue;
                }
                if(node->left!=nullptr){
                    q.push({node->left,to_string(node->left->val)});
                }else{
                    q.push({nullptr,"#"});
                }

                if(node->right!=nullptr){
                    q.push({node->right,to_string(node->right->val)});
                }else{
                    q.push({nullptr,"#"});
                }

            }

        }
        // cout<<"serialized:"<<s<<endl;

        return s;
        
    }

    // Decodes your encoded data to tree.

    TreeNode* generate( string data){

        // if(data[index] == "#"){
        //     return nullptr;
        // }

        queue<TreeNode*> q;
        stringstream s(data);
        string str = "";
        getline(s,str,',');

        if(str == "#"){
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        // cout<<"root:"<<root->val<<endl;

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            getline(s,str,',');

            if(str != "#"){
                // cout<<"node:"<<node->val<<" - left:"<< data[index]<<endl;
                node->left = new TreeNode(stoi(str)); 
                q.push(node->left);
            }else{
                node->left = nullptr;
            }
            getline(s,str,',');


            if(str != "#"){
                // cout<<"node:"<<node->val<<" - right:"<< data[index]<<endl;

                node->right = new TreeNode(stoi(str));
                q.push(node->right);

            }else{
                node->right = nullptr;
            }
            // index++ ;



            
        }

        return root;
        

    }

    
    void print(TreeNode* root){
        if(root==nullptr){
            return;
        }

        queue<TreeNode*> q;


        q.push(root);

        cout<<"deserialize:";
        while(!q.empty()){
            auto node = q.front();
            q.pop();

            cout<<node->val<<" ";

            if(node->left!=nullptr){
                q.push(node->left);
            }

            if(node->right!=nullptr){
                q.push(node->right);
            }
        }



    }
    TreeNode* deserialize(string data) {

       TreeNode* root =  generate(data);
    //    print(root);

       return root;


        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));