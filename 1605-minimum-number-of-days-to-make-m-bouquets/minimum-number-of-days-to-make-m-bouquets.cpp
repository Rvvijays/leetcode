class Solution {
public:

    bool isPossible(vector<int>& bloomDay, int m, int k, int days){
        
        int flowerTook = 0;

        for(auto it : bloomDay) {
            if(it <= days) {
                flowerTook++;

                if(flowerTook == k){
                    m--;
                    flowerTook = 0;
                }
            }else{
                flowerTook = 0;
            }
        }

        if(flowerTook == k){
            m--;
        }

        if(m<=0){
            return true;
        }

        return false;

    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        int low = bloomDay[0];
        int high = bloomDay[0];

        for(auto it : bloomDay){
            if(low > it){
                low = it;
            }

            if(high < it){
                high = it;
            }
        }

        int ans = -1;

        while(low<=high){
            int mid = (low + high)/2;

            if(isPossible(bloomDay, m, k , mid)){
                ans = mid;
                high = mid -1;
            }else{
                low = mid + 1;
            }
        }

        return ans;
        
    }
};