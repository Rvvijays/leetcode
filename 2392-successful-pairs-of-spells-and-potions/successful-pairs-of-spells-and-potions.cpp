class Solution {

    int lowerBound(int num,vector<int> &arr, long long success){

        int low = 0;
        int high = arr.size() - 1;
        // int ans = 0;

        while(low <= high){

            int mid = (high - low)/2 + low;
            long long prod =(long long) arr[mid] * (long long)num;
            if(prod >= success){
                // ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return high;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> pairs(n, 0);
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         if (spells[i] * potions[j] >= success) {
        //             pairs[i]++;
        //         }
        //     }
        // }

        sort(potions.begin(),potions.end());

        for(int i=0; i<n; i++){
            int thresold = spells[i];
            int pos = lowerBound(thresold, potions,success);

            // if(pos >=0){
                pairs[i] = m - pos -1;
            // }

        }

        return pairs;
    }
};