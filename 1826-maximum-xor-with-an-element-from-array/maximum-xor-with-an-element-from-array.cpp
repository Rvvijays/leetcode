class TrieNode {
    TrieNode* children[2];
    int bit;

    public:
    TrieNode(){
        for(int i=0; i<2; i++) {
            children[i] = nullptr;
        }
    }

    void add(int bit) {
        children[bit] = new TrieNode();
    }

    bool contains(int bit) {
        return children[bit] !=nullptr;
    }

    TrieNode* get(int bit) {
        return children[bit];
    }

};

class Trie{
    TrieNode* root;

    public: 
    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;

        for(int i=31; i>=0; i--) {
            int bit = (num >> i) & 1;
            if(!node->contains(bit)) {
                node->add(bit);
            }

            node = node->get(bit);
        }
    }

    int getMax(int num){
        TrieNode* node = root;

        int maxNum = 0;
        for(int i=31; i>=0; i--) {
            int bit = (num >> i) & 1;
            // cout<<"bit:"<<bit<<endl;
             if(node->contains(!bit)) {
                maxNum = maxNum | (1 << i);
                node = node->get(!bit);
            }else{
                node = node->get(bit);
            }
        }

        return maxNum;
    }

};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {

        Trie* tr = new Trie();

        int n = nums.size();

        sort(nums.begin() , nums.end());

        vector<vector<int>> newq;

        for(int i=0; i<queries.size(); i++) {
            vector<int> temp = {queries[i][1],queries[i][0],i};
            newq.push_back(temp);
        }

        sort(newq.begin() , newq.end());

        int i = 0;
        vector<int> ans(queries.size(),-1);
        for(auto it : newq) {
            while(i <n && nums[i] <= it[0]) {
                tr->insert(nums[i]);
                i++;
            }

            if(i!=0){
                ans[it[2]] = tr->getMax(it[1]);
            }
        }

       
        return ans;

      
        
    }
};