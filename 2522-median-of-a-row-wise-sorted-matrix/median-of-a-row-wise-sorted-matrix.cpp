class Solution {
public:

    int lessThanCount(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        for(int i=0; i<n; i++) {

            // cout<<"checking in row: "<<i<<endl;

            int low = 0;
            int high = m-1;
            int pos = -1;

            while(low <= high) {
                int mid = (low + high)/2;

                if(grid[i][mid] <= k) {
                    low = mid + 1;
                    pos = mid;
                }else {
                    high = mid - 1;
                }
            }

            count += pos + 1;

            // cout<<" less numbers : "<<pos+1<<endl;

        }

        // cout<<"total laess: "<<count<<endl;

        return count;

        

    }
    int matrixMedian(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int low = INT_MAX;
        int high = INT_MIN;

        for(int i=0; i<n; i++) {
            low = min(low, grid[i][0]);
            high = max(high, grid[i][m-1]);
        }

        cout<<"low : "<<low<<endl;
        cout<<"high : "<<high<<endl;


        int k = (n*m)/2;
        // int ans = 0;

        while(low <= high) {

            int mid = (high+low)/2;
            // cout<<"checking : "<<mid<<endl;

            int count = lessThanCount(grid,mid);

            cout<<"numbers less than equal to: "<<mid<<" == "<<count<<endl;

            if(count <= k) {
                low = mid +1;
            }else{
                // ans = mid;
                high = mid -1;
            }



        }

        return low;


        
        
        
    }
};