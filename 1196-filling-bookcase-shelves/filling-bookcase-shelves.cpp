class Solution {
public:

    int recursion(int index, int currWidth, vector<vector<int>> &books, int width,int maxShelfHeight,vector<vector<int>> &dp) {

        if(index == books.size()) {
            return maxShelfHeight;
        }

        if(dp[index][currWidth] !=-1) {
            return dp[index][currWidth];
        }


        int currShelf = INT_MAX, nextShelf = INT_MAX;

        int bookWidth = books[index][0];
        int bookHeight = books[index][1];

        // put it in current shelf
        if(bookWidth <= currWidth) {
            currShelf = recursion(index+1, currWidth - bookWidth,books,width, max(maxShelfHeight,bookHeight),dp);
        }

        // put it in next shelf
        nextShelf = maxShelfHeight + recursion(index+1, width - bookWidth,books, width,bookHeight,dp);



        return dp[index][currWidth] = min(currShelf, nextShelf);

        

    }


    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {

        vector<vector<int>> dp(books.size(),vector<int>(shelfWidth+1,-1));
        return recursion(0,0, books, shelfWidth,0,dp);

       
    }
};