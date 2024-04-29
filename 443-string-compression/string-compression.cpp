class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        int left = 0;
        int right = 0;

        while(right < n){
            int count = 0;
            char curr = chars[right];

            while(right < n && chars[right] == curr){
                right++;
                count++;
            }

            chars[left++] = curr;
            if(count>1){
                for(auto it : to_string(count)){
                    chars[left++] = it;
                }
            }
        }

        return left;

    }


};