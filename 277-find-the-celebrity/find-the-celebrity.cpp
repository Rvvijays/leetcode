/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    bool isCelebrity(int i, int n) {
        for (int j = 0; j < n; j++) {
            if(i==j)continue;
            if(knows(i,j) || !knows(j,i)) {
                return false;
            }
        }
        return true;
    }
    int findCelebrity(int n) {



        // for(int i=0; i<n; i++) {
            
        //     if(isCelebrity(i,n)) {
        //         return i;
        //     }
        // }

        int possibleCelebrity = 0;

        for(int i=0; i<n; i++) {
            if(knows(possibleCelebrity,i)){
                possibleCelebrity = i;
            }
        }

        if(isCelebrity(possibleCelebrity,n)) {
            return possibleCelebrity;
        }

        return -1;
        
    }


};