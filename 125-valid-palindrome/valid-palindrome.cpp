class Solution {
public:

    bool palindrome(int i, int j, string s){
        

        while( i <= j && !isalnum(s[i])){
            i++;
        }

        while( i <= j && !isalnum(s[j])){
            j--;
        }

        if(i >= j){
            return true;
        }

        //cout<<"checking "<<s[i]<<" and "<<s[j];
        if(tolower(s[i]) == tolower(s[j])){
            return palindrome(i+1,j-1,s);
        }else{
            return false;
        }

    }

    bool iterative(string s){
        int i =0 ;
        int j = s.size() - 1;

        while(i <= j) {
            if(!isalnum(s[i])){
                i++;
                continue;
            }

            if(!isalnum(s[j])){
                j--;
                continue;
            }

            if(tolower(s[i]) == tolower(s[j])){
                i++;
                j--;
            }else{
                return false;
            }
        }

        return true;
    }

    // bool recursive(int i,string s){
    //     if(i >= s.length()/2){
    //         return true;
    //     }

    //     if()
    // }

    
    bool isPalindrome(string s) {


        // int i =0 ;
        // int j = s.size() - 1;

        // return palindrome(i,j,s); Memory limit exceeded // recursive
        return iterative(s); 
        
        // return recursive(0,s);


        

        return true;
        
    }
};