class Solution {
public:
    int brute(vector<int>& nums) {
        int n = nums.size();

        int maxProd = nums[0];
        for (int i = 0; i < n; i++) {
            int prod = 1;
            for (int j = i; j < n; j++) {
                prod *= nums[j];

                maxProd = max(maxProd, prod);

                // cout<<"prod: "<<prod<<endl;
            }
        }

        return maxProd;
    }

    int maxProduct(vector<int>& nums) {

        int n = nums.size();

        int suffix = 1;
        int prefix = 1;

        int maxProd = nums[0];
        for(int i=0; i<n; i++) {

            if(prefix == 0) {
                prefix =1;
            }

            if(suffix == 0){
                suffix = 1;
            }
            prefix *= nums[i];
            suffix *= nums[n-i-1];

            cout<<"prefix:"<<prefix<<endl;
            cout<<"suffix:"<<suffix<<endl;

            maxProd = max(maxProd ,max(prefix, suffix));

        }

        return maxProd;
    }
};