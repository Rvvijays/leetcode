class Solution {
public:
    int shortestWay(string source, string target) {

        int n = source.size();
        int m = target.size();

        int sourcePointer = 0;
        int targetPointer = 0;

        int count = 1;
        bool startedLoop = false;
        while(targetPointer < m) {

            if (targetPointer < m && source[sourcePointer] == target[targetPointer]) {
                sourcePointer++;
                targetPointer++;
                startedLoop = false;
                continue;
            }

            sourcePointer++;

            if (sourcePointer >= n && targetPointer < m) {
                sourcePointer = 0;
                count++;
                if(startedLoop == true) {
                    return -1;
                }
                startedLoop = true;
            } 


        }
        
        

        return count;

        
    }
};