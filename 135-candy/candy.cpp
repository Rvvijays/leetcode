class Solution {
public:

    int brute(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> leftToRight(n,1);
        vector<int> rightToleft(n,1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]){
                leftToRight[i] += leftToRight[i-1];
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                rightToleft[i] += rightToleft[i+1];
            }
        }


        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += max(leftToRight[i], rightToleft[i]);
        }
        
        return sum;
    }
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();

        vector<int> candies(n,1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i],candies[i+1] + 1);
            }
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += candies[i];
        }

        return sum;
        
       
        
    }
};