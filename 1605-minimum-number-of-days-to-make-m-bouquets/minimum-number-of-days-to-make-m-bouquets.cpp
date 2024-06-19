class Solution {
public:
    int possible(vector<int>& bloomDay, int m, int k, int day) {

        int flowers = 0;
        int bouquets = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                flowers++;
                if (flowers == k) {
                    flowers = 0;
                    // m--;
                    bouquets++;
                }
            } else {
                flowers = 0;
            }
        }

        if (flowers == k) {
            // m--;
            bouquets++;
        }

        // if (m <= 0) {
        //     return true;
        // }

        // return false;

        return bouquets;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        // if (m * k > n) {
        //     return -1;
        // }

        int low = bloomDay[0];
        int high = low;

        for (int i = 0; i < n; i++) {
            low = min(low, bloomDay[i]);
            high = max(high, bloomDay[i]);
        }

        // for (int i = low; i <= high; i++) {
        //     if (possible(bloomDay, m, k, i)) {
        //         return i;
        //     }
        // }

        int ans = -1;

        while (low <= high) {
            int day = (low + high) /2;
            int created = possible(bloomDay, m, k, day);

            if(created >= m) {
                ans = day;
                high = day - 1;
            }else {
                low = day + 1;
            }


        }

        return ans;
    }
};