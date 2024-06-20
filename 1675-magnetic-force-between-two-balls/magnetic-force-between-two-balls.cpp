class Solution {
public:

    int ballsPlaced(vector<int>& position, int dis) {
        int balls = 1;
        int curr = position[0];

        for (int i=1; i<position.size(); i++) {
            if(position[i] - curr >= dis) {
                balls++;
                curr = position[i];
            }
        }

        return balls;

    }
    int maxDistance(vector<int>& position, int m) {

        int n = position.size();

        sort(position.begin(), position.end());
        int low = 0;

        // for (int i=0; i<n; i++) {
        //     low = min(low, position[i]);
        //     maxi = max(maxi, position[i]);
        // }

        // cout<<"min ..."<<low<<endl;

        int high = position[n-1] - position[0];

        // cout<<"max ..."<<high<<endl;


        int ans = 0;

        // for(int i=low; i<=high; i++) {
        //     int possible = ballsPlaced(position, i);

        //     if(m <= possible) {
        //         ans = i;
        //     }
        // }

        while(low <= high) {
            int mid = (low + high)/2;
            int canPlace = ballsPlaced(position, mid);

            // cout<<"mid: "<<mid<<endl;
            // cout<<"balls placed: "<<canPlace<<endl;
            if(canPlace >= m) {
                low = mid + 1;
                ans = mid;
            }else{
                high = mid - 1;
            }

        }

        return ans;


        
    }
};