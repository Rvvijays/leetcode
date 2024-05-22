bool comparator(vector<int> &a, vector<int> &b) {
    return (a[0] == b[0]) ? a[1] > b[1] : a[0] < b[0];
}

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {

        sort(properties.begin(), properties.end(),comparator);

        for(int i=0; i<properties.size(); i++) {
            cout<<properties[i][0]<<", "<<properties[i][1]<<endl;
        }

        int ans = 0;
        int maxDefence = 0;

        for(int i=properties.size() -1; i>=0; i--) {
            if(properties[i][1] < maxDefence) {
                ans++;
            }

            maxDefence = max(properties[i][1],maxDefence);
        }
       

        return ans;
        
    }
};