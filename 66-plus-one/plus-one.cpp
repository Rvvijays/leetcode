class Solution {
public:

    vector<int> optimal(vector<int>& digits){
        int n = digits.size();

        for(int i=n-1; i>=0; i--){
            if(digits[i] == 9){
                digits[i] = 0;
            }else{
                digits[i]++;
                return digits;
            }
        }

        digits.insert(digits.begin(),1);

        return digits;
    }
    vector<int> plusOne(vector<int>& digits) {
        
        // int n = digits.size();
        
        // reverse(digits.begin(),digits.end());
    
        // int carry = 1;
        // int index = 0;
        // while(index < n){
        //     int sum = digits[index] + carry;
            
        //     digits[index] = sum % 10;
        //     carry = sum / 10;
        //     index++;
        // }
        
        // if(carry >0){
        //     digits.push_back(carry);
        // }
        
        // reverse(digits.begin(), digits.end());
        
        // return digits;

        return optimal(digits);
       
        
        
    }
};