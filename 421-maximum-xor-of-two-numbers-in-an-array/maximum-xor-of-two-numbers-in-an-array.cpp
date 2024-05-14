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
        return children[bit] != nullptr;
    }

    TrieNode* get(int bit) {
        return children[bit];
    }

};

class Trie {
    TrieNode* root;

    public:
    Trie(){
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        for(int i=31; i>=0; i--) {
            
            // get ith bit (check ith bit is set or not)
            int bit = (num >> i) & 1;
            if(!node->contains(bit)) {
                node->add(bit);
            }

            node = node->get(bit);
        }
    }

    int getMax(int num) {
        TrieNode* node = root;
        int maxNum = 0;
        for(int i = 31; i>=0; i--) {
            int bit = (num >>i) & 1;
            if(node->contains(1-bit)) {
                // adding 1 to my maxNum (set ith bit)
                maxNum = maxNum | (1 << i);
                node = node->get(1-bit);
            }else{
                node = node->get(bit);
            }
        }

        return maxNum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {

        Trie* tr = new Trie();
        int n = nums.size();

        for(int i=0; i<n; i++) {
            tr->insert(nums[i]);
        }

        int maxi = 0;

        for(int i=0; i<n; i++) {

            int newMa = tr->getMax(nums[i]);

            if(newMa > maxi) {
                maxi = newMa;
            }

        }


        return maxi;
       
        
    }
};