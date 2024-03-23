class Solution {
public:

    int timeTaken(int banana, int h, vector<int>& piles){
        int sum = 0;

        for(auto it : piles) {

            if(it % banana == 0){
                sum += it/banana;
            }else{
                sum += (it/banana) + 1;
            }

            if(sum > h){
                return sum;
            }

        }

        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;

        int high = piles[0];

        for(auto it : piles){
            if(high < it){
                high = it;
            }
        }

        int ans;

        while(low <= high){
            int mid = (low + high)/2;

            if(timeTaken(mid,h,piles) <= h){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;
        
    }
};