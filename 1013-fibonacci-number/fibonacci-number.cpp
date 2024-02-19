class Solution {
public:

    int recursive(int n){

        if(n <0){
            return 0;
        }

        if(n  == 1){
            return 1;
        }

        return recursive(n-1) + recursive(n-2);
    }


    int fib(int n) {
        
        return recursive(n);

        
    }
};