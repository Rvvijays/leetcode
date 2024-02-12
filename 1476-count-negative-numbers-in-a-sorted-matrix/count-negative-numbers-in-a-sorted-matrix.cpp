class Solution {
public:

    int search(vector<int>& row){
        int low = 0;
        int high = row.size() - 1;
        int ans = row.size();
        while(low <= high ){
            int mid = (low + high)/2;

            if(row[mid] < 0){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }

        }
        return ans;
    }
    int countNegatives(vector<vector<int>>& grid) {

        int count = 0;
        for(int i=0; i<grid.size(); i++) {

            int indexOfNeg = search(grid[i]);
            count += grid[i].size() - indexOfNeg;

        }

        return count;

    }
};