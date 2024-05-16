
class Solution {
public:

    int stringChain(string word, unordered_map<string,bool> &list,unordered_map<string,int> &vis) {

        // if(list.find(word)!=list.end()){
        //     return 1;
        // }else{
        //     return 0;
        // }

        if(vis.find(word)!=vis.end()){
            return vis[word];
        }
        
        int len = 1;
        for(int i=0; i<word.size(); i++) {
            string temp = "";

            for(int j=0; j<word.size(); j++) {
                if(i == j){
                    continue;
                }

                temp += word[j];
            }

            if(list.find(temp) != list.end()) {
                cout<<"matched:"<<temp<<endl;
                len = max(len,1 + stringChain(temp,list,vis));
            }
        }

        return vis[word] = len;

    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        // sort(words.begin(), words.end());

        // for(int i = 0; i<n; i++) {
        //     cout<<"word: "<<words[i]<<endl;
        // }

        unordered_map<string,bool> list;

        for(int i=0; i<n; i++) {
            list[words[i]] = true;
        }


        int maxLen = INT_MIN;
        unordered_map<string,int> vis;


        for(int i = 0; i<n; i++) {
            maxLen = max(maxLen, stringChain(words[i],list,vis));
        }


        // queue<pair<string,int>> q;

        // for(int i=0; i<words.size(); i++) {
        //     q.push({words[i],1});
        // }

        // unordered_map<string,int> vis;

        // while(!q.empty()) {
        //     auto it = q.front();
        //     q.pop();



        //     string word = it.first;
        //     int len = it.second;
        //     maxLen = max(len,maxLen);
        //     vis[word] = len;



            

        //     for(int i=0; i<word.size(); i++) {
        //         string temp = "";
        //         for(int j=0; j<word.size(); j++) {
        //             if(i == j) {
        //                 continue;
        //             }

        //             temp += word[j];
        //         }

        //         if(list.find(temp) != list.end()) {
        //             q.push({temp,len+1});
        //         }
        //     }
        // }

        

        return maxLen;
        
    }
};